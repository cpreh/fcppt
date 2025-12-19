//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_DETAIL_SUCCESSES_UNSAFE_HPP_INCLUDED
#define FCPPT_EITHER_DETAIL_SUCCESSES_UNSAFE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either::detail
{
template <typename Result, typename Source>
inline Result successes_unsafe(Source &&_source)
{
  return fcppt::algorithm::map<Result>(
      std::forward<Source>(_source),
      [](auto &&_value)
      {
        FCPPT_PP_PUSH_WARNING
        FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)
        return fcppt::move_if_rvalue<Source>(_value.get_success_unsafe());
        FCPPT_PP_POP_WARNING
      });
}
}

#endif
