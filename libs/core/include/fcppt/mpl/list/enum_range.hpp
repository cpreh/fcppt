//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_ENUM_RANGE_HPP_INCLUDED
#define FCPPT_MPL_LIST_ENUM_RANGE_HPP_INCLUDED

#include <fcppt/enum/max_value.hpp>
#include <fcppt/enum/min_value.hpp>
#include <fcppt/mpl/list/enum_range_start_end.hpp>

namespace fcppt::mpl::list
{
/**
\brief An mpl list over an enum.

\ingroup fcpptenum
TODO(concepts)
*/
template <typename Enum>
using enum_range = fcppt::mpl::list::
    enum_range_start_end<fcppt::enum_::min_value<Enum>, fcppt::enum_::max_value<Enum>>;
}

#endif
