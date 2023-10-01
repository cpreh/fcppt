//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_TRAITS_IMPLICATION_V_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IMPLICATION_V_HPP_INCLUDED

#include <fcppt/type_traits/implication.hpp>

namespace fcppt::type_traits
{
/**
\brief The implication function: \a Left -> \a Right.
\ingroup fcppttype_traits
\see fcppt::type_traits::implication
*/
template <typename Left, typename Right>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool implication_v = fcppt::type_traits::implication<Left, Right>::value;
}

#endif
