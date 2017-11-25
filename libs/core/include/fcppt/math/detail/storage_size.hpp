//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STORAGE_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STORAGE_SIZE_HPP_INCLUDED

#include <fcppt/container/array_size.hpp>
#include <fcppt/math/detail/is_static_storage.hpp>
#include <fcppt/config/external_begin.hpp>
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
	typename Enable = void
>
struct storage_size;

template<
	typename T
>
struct storage_size<
	T,
	typename
	std::enable_if<
		!fcppt::math::detail::is_static_storage<
			T
		>::value
	>::type
>
:
T::static_size
{
};

template<
	typename T
>
struct storage_size<
	T,
	typename
	std::enable_if<
		fcppt::math::detail::is_static_storage<
			T
		>::value
	>::type
>
:
fcppt::container::array_size<
	typename
	T::array_type
>
{
};

}
}
}

#endif
