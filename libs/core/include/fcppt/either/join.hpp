//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_JOIN_HPP_INCLUDED
#define FCPPT_EITHER_JOIN_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/is_object_v.hpp>
#include <fcppt/either/object_concept.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Removes one layer of eithers.

\ingroup fcppteither

If the outer either has failure <code>f_1</code>, then <code>f_1</code> is returned.
Otherwise, if the inner either has failure <code>f_2</code>, then <code>f_2</code> is returned.
Otherwise, the success value of the inner either is returned.
*/
template <fcppt::either::object_concept Either>
fcppt::either::object<
    fcppt::either::failure_type<Either>,
    fcppt::either::success_type<fcppt::either::success_type<Either>>>
join(Either &&_either) requires fcppt::either::is_object_v<fcppt::either::success_type<Either>> &&
    std::is_same_v<
        fcppt::either::failure_type<Either>,
        fcppt::either::failure_type<fcppt::either::success_type<Either>>>
{
  return fcppt::either::bind(
      std::forward<Either>(_either),
      [](auto &&_value) { return fcppt::move_if_rvalue<Either>(_value); });
}
}

#endif
