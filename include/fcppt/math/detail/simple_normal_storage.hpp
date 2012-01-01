//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_SIMPLE_NORMAL_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_SIMPLE_NORMAL_STORAGE_HPP_INCLUDED

#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/math/detail/dynamic_storage.hpp>
#include <fcppt/math/detail/static_storage.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T,
	typename N
>
struct simple_normal_storage
:
math::detail::static_storage<
	T,
	N::value
>
{
};

template<
	typename T
>
struct simple_normal_storage<
	T,
	math::detail::dynamic_size
>
:
math::detail::dynamic_storage<
	T
>
{
};

}
}
}

#endif
