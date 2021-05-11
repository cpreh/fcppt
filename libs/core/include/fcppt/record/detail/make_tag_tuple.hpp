//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_MAKE_TAG_TUPLE_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_MAKE_TAG_TUPLE_HPP_INCLUDED

#include <fcppt/tuple/element.hpp>
#include <fcppt/tuple/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::record::detail
{
template <typename TagTuple>
[[nodiscard]] inline TagTuple make_tag_tuple()
{
  return fcppt::tuple::init<TagTuple>(
      []<std::size_t Index>(std::integral_constant<std::size_t, Index>)
      { return fcppt::tuple::element<Index, TagTuple>{}; });
}
}

#endif
