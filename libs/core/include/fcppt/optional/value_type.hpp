//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_VALUE_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONAL_VALUE_TYPE_HPP_INCLUDED

#include <fcppt/optional/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief The value type of an optional.

\ingroup fcpptoptional
*/
template <fcppt::optional::object_concept Optional>
using value_type = fcppt::type_traits::value_type<std::remove_cvref_t<Optional>>;

}

#endif
