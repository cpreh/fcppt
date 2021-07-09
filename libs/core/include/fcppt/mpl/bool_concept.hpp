//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_BOOL_CONCEPT_HPP_INCLUDED
#define FCPPT_MPL_BOOL_CONCEPT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
/**
\brief Concept for boolean constants.
\ingroup fcpptmpl

A type is a boolean constant if and only if it is of the form
<code>std::bool_constant<V></code> for any <code>bool V</code>.
*/
template <typename T>
concept bool_concept = std::is_same_v<typename T::type, std::true_type> ||
    std::is_same_v<typename T::type, std::false_type>;
}

#endif
