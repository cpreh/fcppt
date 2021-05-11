//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_OUTPUT_HPP_INCLUDED
#define FCPPT_TUPLE_OUTPUT_HPP_INCLUDED

#include <fcppt/not.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_metal.hpp>
#include <fcppt/metal/interval.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <cstddef>
#include <ostream>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Outputs an tuple to a stream

\ingroup fcppttuple
*/
template <typename Ch, typename Traits, typename... Types>
std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::tuple::object<Types...> const &_tuple)
{
  _stream << _stream.widen('(');

  fcppt::algorithm::loop(
      fcppt::metal::interval<std::size_t, 0U, sizeof...(Types)>{},
      [&_stream, &_tuple]<std::size_t Index>(fcppt::tag<std::integral_constant<std::size_t, Index>>)
      {
        _stream << fcppt::tuple::get<Index>(_tuple);
        if constexpr (Index != sizeof...(Types) - 1U)
        {
          _stream << _stream.widen(',');
        }
      });

  return _stream << _stream.widen(')');
}
}

#endif
