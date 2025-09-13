//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_VARIANT_TYPE_FWD_HPP_INCLUDED
#define FCPPT_EITHER_VARIANT_TYPE_FWD_HPP_INCLUDED

#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/either/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief The variant type of an either.

\ingroup fcppteither
*/
template <fcppt::either::object_concept Either>
using variant_type = fcppt::variant::object<
    fcppt::either::failure_type<std::remove_cvref_t<Either>>,
    fcppt::either::success_type<std::remove_cvref_t<Either>>>;
}

#endif
