//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_UNARY_TYPE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_UNARY_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <utility> // IWYU pragma: keep
#include <fcppt/config/external_end.hpp>

#define FCPPT_MATH_DETAIL_UNARY_TYPE(left, op) decltype(op std::declval<left>())

#endif
