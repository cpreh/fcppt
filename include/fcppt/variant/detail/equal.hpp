//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_EQUAL_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_EQUAL_HPP_INCLUDED

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
	typename Types
>
class equal
{
	FCPPT_NONASSIGNABLE(
		equal
	);
public:
	typedef
	fcppt::variant::object<
		Types
	> variant_type;

	explicit
	equal(
		variant_type const &_left
	)
	:
		left_(
			_left
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
			left_. template get<
				OtherType
			>()
			== _right;
	}
private:
	variant_type const &left_;
};

}
}
}

#endif
