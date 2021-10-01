//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TREE_DETAIL_PRINT_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DETAIL_PRINT_HPP_INCLUDED

#include <fcppt/output.hpp>
#include <fcppt/algorithm/repeat.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::tree::detail
{
template <typename Ch, typename Traits, typename Value>
void print(
    std::basic_ostream<Ch, Traits> &_stream,
    fcppt::container::tree::object<Value> const &_tree,
    unsigned const _indent)
{
  fcppt::algorithm::repeat(_indent, [&_stream] { _stream << _stream.widen('\t'); });

  _stream << fcppt::output(_tree.value()) << _stream.widen('\n');

  for (auto const &child : _tree)
  {
    fcppt::container::tree::detail::print(_stream, child, _indent + 1U);
  }
}

}

#endif
