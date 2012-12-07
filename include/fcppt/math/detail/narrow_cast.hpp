//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_NARROW_CAST_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_NARROW_CAST_HPP_INCLUDED

#include <fcppt/math/detail/structure_cast_fun.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/mpl/less.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T,
	typename U
>
T const
narrow_cast(
	U const &_other
)
{
	typedef detail::structure_cast_fun<
		typename T::value_type
	> op_type;

	op_type const op = op_type();

	static_assert(
		boost::mpl::less<
			typename T::dim_wrapper,
			typename U::dim_wrapper
		>::value,
		"narrow_cast can only cast to types with lesser dimensions"
	);

	return
		T(
			boost::make_transform_iterator(
				_other.begin(),
				op
			),
			boost::make_transform_iterator(
				_other.begin() + T::dim_wrapper::value,
				op
			)
		);
}

}
}
}

#endif
