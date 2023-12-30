//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_APPLY_V_HPP_INCLUDED
#define FCPPT_MPL_APPLY_V_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/lambda_concept.hpp> // IWYU pragma: keep

namespace fcppt::mpl
{
/**
\brief Calls a lambda.
\ingroup fcpptmpl
\see fcppt::mpl::apply
*/
template<fcppt::mpl::lambda_concept L,typename... Args>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool apply_v = fcppt::mpl::apply<L,Args...>::value;

}

#endif
