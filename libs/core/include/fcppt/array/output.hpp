//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_OUTPUT_HPP_INCLUDED
#define FCPPT_ARRAY_OUTPUT_HPP_INCLUDED

#include <fcppt/not.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_metal.hpp>
#include <fcppt/array/get.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/metal/interval.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <cstddef>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Outputs an array to a stream

\ingroup fcpptarray
*/
template <typename Ch, typename Traits, typename Type, std::size_t Size>
std::basic_ostream<Ch, Traits> &operator<<(
    std::basic_ostream<Ch, Traits> &_stream, fcppt::array::object<Type, Size> const &_array)
{
  _stream << _stream.widen('[');

  fcppt::algorithm::loop(
      fcppt::metal::interval<std::size_t, 0U, Size>{}, [&_stream, &_array](auto const _index) {
        FCPPT_USE(_index);
        using index = fcppt::tag_type<decltype(_index)>;

        _stream << fcppt::array::get<index::value>(_array);
        if constexpr (index::value != Size - 1U)
        {
          _stream << _stream.widen(',');
        }
      });

  return _stream << _stream.widen(']');
}

}

#endif
