//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_LOOP_BREAK_RECORD_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_RECORD_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/loop_break_impl_fwd.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/record/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
template <typename Range>
struct loop_break_impl<Range, std::enable_if_t<fcppt::record::is_object<Range>::value>>
{
  template <typename Record, typename Body>
  inline static void execute(Record &&_range, Body const &_body)
  {
    fcppt::algorithm::loop_break_impl<typename std::remove_cvref_t<Record>::tuple>:: template execute(
        fcppt::move_if_rvalue<Record>(_range.impl()), _body);
  }
};

}

#endif
