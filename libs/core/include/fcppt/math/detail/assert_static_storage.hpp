//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/math/is_static_storage.hpp> // IWYU pragma: keep

#define FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(storage) \
  static_assert( \
      fcppt::math::is_static_storage<storage>::value, "S must be a static storage")

#endif
