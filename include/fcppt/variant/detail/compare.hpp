//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_COMPARE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_COMPARE_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object_decl.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Types,
	typename Compare
>
class compare
{
	FCPPT_NONASSIGNABLE(
		compare
	);
public:
	typedef
	fcppt::variant::object<
		Types
	> variant_type;

	compare(
		variant_type const &_left,
		Compare const &_compare
	)
	:
		left_(
			_left
		),
		compare_(
			_compare
		)
	{
	}

	typedef bool result_type;

	template<
		typename OtherType
	>
	result_type
	operator()(
		OtherType const &_right
	) const
	{
		return
			fcppt::variant::holds_type<
				OtherType
			>(
				left_
			)
			&&
			compare_(
				left_. template get<
					OtherType
				>(),
				_right
			);
	}
private:
	variant_type const &left_;

	Compare const compare_;
};

}
}
}

#endif
