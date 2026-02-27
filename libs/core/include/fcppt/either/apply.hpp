//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_APPLY_HPP_INCLUDED
#define FCPPT_EITHER_APPLY_HPP_INCLUDED

#include <fcppt/absurd.hpp>
#include <fcppt/identity.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/concepts/invocable_move.hpp> // IWYU pragma: keep
#include <fcppt/either/failure_opt.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_move_type.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief Applies a function to several eithers.

\ingroup fcppteither

For eithers <code>e_1 = _either1</code> and <code>e_2, ..., e_n =
_eithers</code>. If there is a smallest <code>i</code> such that
<code>e_i</code> is set to failure <code>f</code>, then
<code>f</code> is returned. Otherwise, <code>e_1, ...., e_n</code> are
set to successes <code>s_1,...,s_n</code> and the result is
<code>_function(s_1,...,s_n)</code>.
*/
template <
    fcppt::either::object_concept Either1,
    fcppt::either::object_concept... Eithers,
    fcppt::concepts::invocable_move<
        fcppt::either::success_move_type<Either1>,
        fcppt::either::success_move_type<Eithers>...> Function>
[[nodiscard]] fcppt::either::object<
    fcppt::either::failure_type<Either1>,
    std::invoke_result_t<
        Function,
        fcppt::either::success_move_type<Either1>,
        fcppt::either::success_move_type<Eithers>...>>
apply(Function const &_function, Either1 &&_either1, Eithers &&..._eithers) requires(
    std::is_same_v<fcppt::either::failure_type<Either1>, fcppt::either::failure_type<Eithers>>
        &&...)
{
  using failure = fcppt::either::failure_type<Either1>;

  using result_type = fcppt::either::object<
      failure,
      std::invoke_result_t<
          Function,
          fcppt::either::success_move_type<Either1>,
          fcppt::either::success_move_type<Eithers>...>>;

  using optional_failure = fcppt::optional::object<failure>;

  constexpr std::size_t const num_eithers{sizeof...(Eithers) + 1U};

  using failure_array = fcppt::array::object<optional_failure, num_eithers>;

  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)

  return fcppt::algorithm::all_of(
             fcppt::array::object<bool, num_eithers>{
                 _either1.has_success(), _eithers.has_success()...},
             fcppt::identity{})
             ? result_type(_function(
                   fcppt::move_if_rvalue<Either1>(_either1.get_success_unsafe()),
                   fcppt::move_if_rvalue<Eithers>(_eithers.get_success_unsafe())...))
             : result_type{
                   [](failure_array &&_failures) // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
                   {
                     fcppt::optional::object<typename failure_array::iterator> const failure_opt{
                         fcppt::algorithm::find_if_opt(
                             _failures,
                             [](optional_failure const &_failure)
                             { return _failure.has_value(); })};

                     using iterator = failure_array::iterator;

                     // Silence -Wnull-dereference warning
                     iterator const failure_it{
                         failure_opt.has_value() ? failure_opt.get_unsafe()
                                                 : fcppt::absurd<iterator>()};

                     return std::move(failure_it->get_unsafe());
                   }(failure_array{
                       fcppt::either::failure_opt(std::forward<Either1>(_either1)),
                       fcppt::either::failure_opt(std::forward<Eithers>(_eithers))...})};

  FCPPT_PP_POP_WARNING
}
}

#endif
