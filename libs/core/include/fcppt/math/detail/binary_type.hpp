//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_BINARY_TYPE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_BINARY_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

#define FCPPT_MATH_DETAIL_BINARY_TYPE(left, op, right) \
  decltype(std::declval<left>() op std::declval<right>())

#endif
