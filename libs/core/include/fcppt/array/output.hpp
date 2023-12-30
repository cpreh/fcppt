//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_OUTPUT_HPP_INCLUDED
#define FCPPT_ARRAY_OUTPUT_HPP_INCLUDED

#include <fcppt/output.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp> // IWYU pragma: keep
#include <fcppt/array/get.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <ostream>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Outputs an array to a stream.

\ingroup fcpptarray
*/
template <typename Ch, typename Traits, typename Type, std::size_t Size>
std::basic_ostream<Ch, Traits> &operator<<(
    std::basic_ostream<Ch, Traits> &_stream, fcppt::array::object<Type, Size> const &_array)
{
  _stream << _stream.widen('[');

  fcppt::algorithm::loop(
      fcppt::mpl::list::interval<fcppt::mpl::size_type<0U>, fcppt::mpl::size_type<Size>>{},
      [&_stream, &_array]<std::size_t Index>(fcppt::tag<std::integral_constant<std::size_t, Index>>)
      {
        _stream << fcppt::output(fcppt::array::get<Index>(_array));
        if constexpr (Index != Size - 1U)
        {
          _stream << _stream.widen(',');
        }
      });

  return _stream << _stream.widen(']');
}

}

#endif
