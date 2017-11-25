//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_IS_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_IS_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/math/detail/static_storage_fwd.hpp>
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
	typename Type
>
struct is_static_storage
:
std::false_type
{
};

template<
	typename T,
	fcppt::math::size_type N
>
struct is_static_storage<
	fcppt::math::detail::static_storage<
		T,
		N
	>
>
:
std::true_type
{
};

}
}
}

#endif
