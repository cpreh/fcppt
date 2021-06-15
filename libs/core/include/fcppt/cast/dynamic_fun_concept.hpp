//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_DYNAMIC_FUN_CONCEPT_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_FUN_CONCEPT_HPP_INCLUDED

#include <fcppt/cast/dynamic_any_fun_fwd.hpp>
#include <fcppt/cast/dynamic_cross_fun_fwd.hpp>
#include <fcppt/cast/dynamic_fun_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast
{

/**
\brief Concept for dynamic cast functions.
\ingroup fcpptcasts
*/
template <typename T>
concept dynamic_fun_concept = std::is_same_v<T, fcppt::cast::dynamic_fun> ||
    std::is_same_v<T, fcppt::cast::dynamic_any_fun> ||
    std::is_same_v<T, fcppt::cast::dynamic_cross_fun>;
}

#endif
