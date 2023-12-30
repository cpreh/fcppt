//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_SEQUENCE_HPP_INCLUDED
#define FCPPT_EITHER_SEQUENCE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/find_by_opt.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/either/failure_opt.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/either/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/either/success_type.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Sequences a container of eithers.

\ingroup fcppteither

Let \a _source be a container <code>[e_1,...e_n]</code>,
where <code>e_i</code> has type <code>%fcppt::either::object<F,S_i></code>.
If there is an <code>i</code> such
that <code>e_i</code> has failure <code>f</code> and there is no <code>j <
i</code> such that <code>e_j</code> has a failure, then <code>f</code> is
returned. Otherwise, all eithers have success values,
<code>[s_1,...,s_n]</code>, and <code>Result{s_1,...,s_n}</code> is returned.

TODO(concepts)
*/
template <fcppt::either::object_concept Result, typename Source>
[[nodiscard]]
Result sequence(Source &&_source) // NOLINT(cppcoreguidelines-missing-std-forward)
{
  return fcppt::optional::maybe(
      fcppt::algorithm::find_by_opt<fcppt::either::failure_type<Result>>(
          _source, [](auto const &_either) { return fcppt::either::failure_opt(_either); }),
      [&_source] {
        return Result{fcppt::algorithm::map<fcppt::either::success_type<Result>>(
            std::forward<Source>(_source), [](auto &&_value) {
              FCPPT_PP_PUSH_WARNING
              FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)
              return fcppt::move_if_rvalue<Source>(_value.get_success_unsafe());
              FCPPT_PP_POP_WARNING
            })};
      },
      [](auto &&_failure) {
        return Result{std::forward<decltype(_failure)>(_failure)};
      });
}
}

#endif
