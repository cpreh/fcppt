//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_MOVE_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONAL_MOVE_TYPE_HPP_INCLUDED

#include <fcppt/move_if_rvalue_type.hpp>
#include <fcppt/optional/object_concept.hpp>
#include <fcppt/optional/reference_type.hpp>

namespace fcppt::optional
{
/**
\brief The moved inner type of an optional.

\ingroup fcpptoptional
*/
template <fcppt::optional::object_concept Optional>
using move_type = fcppt::move_if_rvalue_type<Optional, fcppt::optional::reference_type<Optional>>;
}

#endif
