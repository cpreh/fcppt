//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONCEPTS_INVOCABLE_HPP_INCLUDED
#define FCPPT_CONCEPTS_INVOCABLE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::concepts
{

/**
\brief Same as std::invcoable.
\ingroup fcpptconcepts

This is not implemented in libc++ yet.
*/
template<typename Function, typename... Args>
concept invocable = requires(Function &&_function, Args && ..._args)
{
  std::invoke(std::forward<Function>(_function), std::forward<Args>(_args)...);
};

}

#endif
