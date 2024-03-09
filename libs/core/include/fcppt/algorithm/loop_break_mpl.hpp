//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_LOOP_BREAK_MPL_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_MPL_HPP_INCLUDED

#include <fcppt/algorithm/loop_break_impl_fwd.hpp>
#include <fcppt/mpl/list/for_each_break.hpp>
#include <fcppt/mpl/list/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
template <typename Range>
struct loop_break_impl<Range, std::enable_if_t<fcppt::mpl::list::is_object<Range>::value>>
{
  template <typename Body>
  static void execute(Range const &, Body const &_body)
  {
    fcppt::mpl::list::for_each_break<Range>(_body);
  }
};

}

#endif
