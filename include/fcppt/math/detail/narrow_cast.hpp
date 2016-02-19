//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_NARROW_CAST_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_NARROW_CAST_HPP_INCLUDED

#include <fcppt/math/detail/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/less.hpp>
#include <type_traits>
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
inline
T
narrow_cast(
	U const &_other
)
{
	static_assert(
		std::is_same<
			typename T::value_type,
			typename U::value_type
		>::value,
		"narrow_cast can only be used on the same value_types"
	);

	static_assert(
		boost::mpl::less<
			typename T::dim_wrapper,
			typename U::dim_wrapper
		>::value,
		"narrow_cast can only cast to types with lesser dimensions"
	);

	return
		fcppt::math::detail::init<
			T
		>(
			[
				&_other
			](
				typename T::size_type const _index
			)
			{
				return
					_other[
						_index
					];
			}
		);
}

}
}
}

#endif
