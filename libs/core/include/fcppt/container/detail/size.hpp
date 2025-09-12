//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_DETAIL_SIZE_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_SIZE_HPP_INCLUDED

#include <fcppt/container/detail/has_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::detail
{
template <typename Source>
inline typename std::iterator_traits<typename Source::iterator>::difference_type
size(Source const &_source)
  requires(!fcppt::container::detail::has_size<Source>::value)
{
  return std::distance(_source.begin(), _source.end());
}

template <typename Source>
inline auto size(Source const &_source)
  requires fcppt::container::detail::has_size<Source>::value
{
  return _source.size();
}
}

#endif
