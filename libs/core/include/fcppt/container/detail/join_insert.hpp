//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_DETAIL_JOIN_INSERT_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_JOIN_INSERT_HPP_INCLUDED

#include <fcppt/container/detail/has_insert_range.hpp>

namespace fcppt::container::detail
{
template <typename Result, typename Iterator>
inline void join_insert(Result &_result, Iterator const _begin, Iterator const _end)
  requires(!fcppt::container::detail::has_insert_range<Result>::value)
{
  _result.insert(_result.end(), _begin, _end);
}

template <typename Result, typename Iterator>
inline void join_insert(Result &_result, Iterator const _begin, Iterator const _end)
  requires(fcppt::container::detail::has_insert_range<Result>::value)
{
  _result.insert(_begin, _end);
}
}

#endif
