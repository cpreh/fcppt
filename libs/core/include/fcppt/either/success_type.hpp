//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_SUCCESS_TYPE_HPP_INCLUDED
#define FCPPT_EITHER_SUCCESS_TYPE_HPP_INCLUDED

#include <fcppt/either/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief The success type of an either.

\ingroup fcppteither
*/
template <fcppt::either::object_concept Either>
using success_type = typename std::remove_cvref_t<Either>::success;

}

#endif
