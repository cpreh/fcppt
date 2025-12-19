//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_SEQUENCE_ALL_HPP_INCLUDED
#define FCPPT_EITHER_SEQUENCE_ALL_HPP_INCLUDED

#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/either/construct.hpp>
#include <fcppt/either/failure_opt.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/object_concept.hpp>
#include <fcppt/either/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/either/success_type.hpp>
#include <fcppt/either/detail/successes_unsafe.hpp>
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
Let <code>F = [f_1,...,f_m]</code> be the failures of [e_1,...,e_n] in order.
If <code>m > 0</code>, then <code>Result{F}</code> is returned.
Otherwise, all eithers have success values,
<code>[s_1,...,s_n]</code>, and <code>Result{s_1,...,s_n}</code> is returned.

TODO(concepts)
*/
template <fcppt::either::object_concept Result, typename Source>
[[nodiscard]]
Result sequence_all(Source &&_source) // NOLINT(cppcoreguidelines-missing-std-forward)
{
  using failure_container = fcppt::either::failure_type<Result>;
  failure_container failures{fcppt::algorithm::map_optional<failure_container>(
      _source, [](auto const &_either) { return fcppt::either::failure_opt(_either); })};

  return fcppt::either::construct(
      failures.empty(),
      [&_source]
      {
        return fcppt::either::detail::successes_unsafe<fcppt::either::success_type<Result>>(
            std::forward<Source>(_source));
      },
      [&failures] { return std::move(failures); });
}

}

#endif
