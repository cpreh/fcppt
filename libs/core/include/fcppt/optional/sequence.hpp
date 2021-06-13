//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_SEQUENCE_HPP_INCLUDED
#define FCPPT_OPTIONAL_SEQUENCE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/contains_if.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/detail/check_sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
/**
\brief Turns a container of optionals into an optional container.

\ingroup fcpptoptional

Let \a _source be a container <code>[o_1,...o_n]</code> of type
<code>%fcppt::optional::object\<T\></code>. If there is an <code>i</code> such
that <code>o_i</code> is nothing, then nothing is
returned. Otherwise, all optionals have a value,
<code>[v_1,...,v_n]</code>, and
<code>%fcppt::optional::object\<ResultContainer\>{v_1,...,v_n}</code> is
returned.

\tparam ResultContainer Must be a container of type <code>T</code>

\tparam Source Must be an optional type

// TODO(concepts)
*/
template <typename ResultContainer, typename Source>
fcppt::optional::object<ResultContainer> sequence(Source &&_source)
{
  fcppt::optional::detail::
      check_sequence<ResultContainer, std::remove_cvref_t<Source>> const test{};

  FCPPT_USE(test);

  return fcppt::optional::make_if(
      !fcppt::algorithm::contains_if(
          _source, [](auto const &_optional) -> bool { return !_optional.has_value(); }),
      [&_source] {
        return fcppt::algorithm::map<ResultContainer>(
            std::forward<Source>(_source),
            [](auto &&_value) { return fcppt::move_if_rvalue<Source>(_value.get_unsafe()); });
      });
}

}

#endif
