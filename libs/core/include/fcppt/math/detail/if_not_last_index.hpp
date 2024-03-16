//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_IF_NOT_LAST_INDEX_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_IF_NOT_LAST_INDEX_HPP_INCLUDED

namespace fcppt::math::detail
{
template <typename Index, typename Size, typename Function>
inline void if_not_last_index(Index, Size, Function const &_function)
  requires(Index::value != Size::value - 1U)
{
  _function();
}

template <typename Index, typename Size, typename Function>
inline void if_not_last_index(Index, Size, Function const &)
  requires(Index::value == Size::value - 1U)
{
}
}

#endif
