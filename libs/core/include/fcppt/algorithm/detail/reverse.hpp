//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_DETAIL_REVERSE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_REVERSE_HPP_INCLUDED

#include <fcppt/not.hpp>
#include <fcppt/range/begin.hpp>
#include <fcppt/range/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm::detail
{
template <typename Container>
inline Container reverse(Container &&_container)
  requires(fcppt::not_(std::is_lvalue_reference_v<Container>))
{
  std::reverse(fcppt::range::begin(_container), fcppt::range::end(_container));

  return std::forward<Container>(_container);
}

template <typename Container>
inline Container reverse(Container const &_container)
{
  return fcppt::algorithm::detail::reverse(Container(_container));
}

}

#endif
