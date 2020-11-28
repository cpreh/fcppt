//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_JOIN_STRINGS_HPP_INCLUDED
#define FCPPT_ALGORITHM_JOIN_STRINGS_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/range/begin.hpp>
#include <fcppt/range/end.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{
/**
\brief Joins a range of strings, using a delimiter

\ingroup fcpptalgorithm

Joins \a _range, inserting \a _delim between every pair of consecutive elements.

Example:

\snippet algorithm.cpp join_strings

\tparam Range A range of strings.
*/
template <typename Range>
fcppt::type_traits::value_type<Range>
join_strings(Range const &_range, fcppt::type_traits::value_type<Range> const &_delim)
{
  fcppt::type_traits::value_type<Range> result;

  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)

  auto const end{fcppt::range::end(_range)};

  for (auto it(fcppt::range::begin(_range)); it != end; ++it)
  {
    result += *it;

    if (
        // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
        std::next(it) != end)
    {
      result += _delim;
    }
  }

  FCPPT_PP_POP_WARNING

  return result;
}
}
}

#endif
