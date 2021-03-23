//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_IS_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_IS_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/math/detail/is_static_storage.hpp>

namespace fcppt::math
{
template <typename T>
using is_static_storage = typename fcppt::math::detail::is_static_storage<T>::type;
}

#endif
