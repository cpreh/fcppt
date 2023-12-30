//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_IF_HPP_INCLUDED
#define FCPPT_MPL_IF_HPP_INCLUDED

#include <fcppt/mpl/bool_concept.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
/**
\brief The if-then-else function.
\ingroup fcpptmpl
Similar to <code>std::conditional_t</code> but takes a
<code>bool_concept</code>, i.e., a <code>std::bool_constant<V></code> for any
<code>bool V</code> instead of <code>V</code> directly.
*/
template<fcppt::mpl::bool_concept B, typename T, typename F>
using if_ = std::conditional_t<B::value, T, F>;

}

#endif
