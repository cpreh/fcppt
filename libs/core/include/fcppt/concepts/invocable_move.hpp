//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONCEPTS_INVOCABLE_MOVE_HPP_INCLUDED
#define FCPPT_CONCEPTS_INVOCABLE_MOVE_HPP_INCLUDED

#include <fcppt/concepts/invocable.hpp>
#include <fcppt/concepts/move_constructible.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::concepts
{

/**
\brief Like std::invocable but also requires the result to be move constructible.
\ingroup fcpptconcepts
*/
template <typename Function, typename... Args>
concept invocable_move = fcppt::concepts::invocable<Function, Args...> &&
    fcppt::concepts::move_constructible<std::invoke_result_t<Function, Args...>>;
}

#endif
