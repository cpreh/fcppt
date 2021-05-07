//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_SEQUENCE_HPP_INCLUDED
#define FCPPT_EITHER_SEQUENCE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace either
{
/**
\brief Sequences a container of eithers

\ingroup fcppteither

Let \a _source be a container <code>[e_1,...e_n]</code> of type
<code>%fcppt::either::object<F,S></code>. If there is an <code>i</code> such
that <code>e_i</code> has failure <code>f</code> and there is no <code>j <
i</code> such that <code>e_j</code> has a failure, then <code>f</code> is
returned. Otherwise, all eithers have success values,
<code>[s_1,...,s_n]</code>, and
<code>%fcppt::either::object<F,ResultContainer>{s_1,...,s_n}</code> is
returned.

\tparam ResultContainer Must be a container of type <code>S</code>

\tparam Source Must be an either type
*/
template <typename ResultContainer, typename Source>
fcppt::either::object<
    fcppt::either::failure_type<
        fcppt::type_traits::value_type<std::remove_cvref_t<Source>>>,
    ResultContainer>
sequence(Source &&_source)
{
  using source_type = std::remove_reference_t<Source>;

  using source_either = fcppt::type_traits::value_type<std::remove_const_t<source_type>>;

  static_assert(
      fcppt::either::is_object<source_either>::value, "The source must be a container of eithers");

  using result_type =
      fcppt::either::object<fcppt::either::failure_type<source_either>, ResultContainer>;

  static_assert(
      std::is_same_v<
          fcppt::type_traits::value_type<ResultContainer>,
          fcppt::either::success_type<source_either>>,
      "ResultContainer must be a container of the source's success type");

  return fcppt::optional::maybe(
      fcppt::algorithm::find_if_opt(
          _source, [](auto const &_either) { return _either.has_failure(); }),
      [&_source] {
        return result_type{fcppt::algorithm::map<ResultContainer>(
            std::forward<Source>(_source), [](auto &&_value) {
              FCPPT_PP_PUSH_WARNING
              FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)
              return fcppt::move_if_rvalue<Source>(_value.get_success_unsafe());
              FCPPT_PP_POP_WARNING
            })};
      },
      [](fcppt::container::to_iterator_type<source_type> const &_iterator) {
        return result_type{fcppt::move_if_rvalue<Source>(_iterator->get_failure_unsafe())};
      });
}

}
}

#endif
