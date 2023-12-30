//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MOVE_IF_RVALUE_TYPE_HPP_INCLUDED
#define FCPPT_MOVE_IF_RVALUE_TYPE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Type of #fcppt::move_if_rvalue

\ingroup fcpptvarious
*/
template <typename Type, typename Arg>
using move_if_rvalue_type = decltype(fcppt::move_if_rvalue<Type>(std::declval<Arg>()));

}

#endif
