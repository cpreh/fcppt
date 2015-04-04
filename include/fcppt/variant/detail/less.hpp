//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_LESS_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_LESS_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/variant/object_impl.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Types
>
class less
{
	FCPPT_NONASSIGNABLE(
		less
	);
public:
	typedef
	fcppt::variant::object<
		Types
	> variant_type;

	explicit
	less(
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
			left_. template get_unsafe<
				OtherType
			>()
			<
			_right;
	}
private:
	variant_type const &left_;
};

}
}
}

#endif
