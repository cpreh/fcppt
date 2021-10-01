//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_TRAITS_IMPLICATION_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IMPLICATION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::type_traits
{
/**
\brief The implication function: \a Left -> \a Right

\ingroup fcppttype_traits

Calculates the implication of \a Left and \a Right. Equal to (not \a Left) or
\a Right)

\tparam Left A boolean expression

\tparam Right A boolean expression
*/
template <typename Left, typename Right>
using implication = std::disjunction<std::negation<Left>, Right>;

}

#endif
