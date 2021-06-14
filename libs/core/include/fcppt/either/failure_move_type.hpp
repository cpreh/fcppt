//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_FAILURE_MOVE_TYPE_HPP_INCLUDED
#define FCPPT_EITHER_FAILURE_MOVE_TYPE_HPP_INCLUDED

#include <fcppt/move_if_rvalue_type.hpp>
#include <fcppt/either/object_concept.hpp>
#include <fcppt/either/failure_reference_type.hpp>

namespace fcppt::either
{
/**
\brief The moved failure type of an either.

\ingroup fcppteither
*/
template <fcppt::either::object_concept Either>
using failure_move_type =
    fcppt::move_if_rvalue_type<Either, fcppt::either::failure_reference_type<Either>>;
}

#endif
