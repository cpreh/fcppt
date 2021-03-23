//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_MAKE_TAG_TUPLE_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_MAKE_TAG_TUPLE_HPP_INCLUDED

#include <fcppt/tuple/element.hpp>
#include <fcppt/tuple/init.hpp>

namespace fcppt::record::detail
{
template <typename TagTuple>
[[nodiscard]] inline TagTuple make_tag_tuple()
{
  return fcppt::tuple::init<TagTuple>(
      [](auto const _index) { return fcppt::tuple::element<_index(), TagTuple>{}; });
}

}

#endif
