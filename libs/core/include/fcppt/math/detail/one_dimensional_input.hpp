//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_INPUT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_INPUT_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/io/expect.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/if_not_last_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::detail
{
template <typename Ch, typename Traits, typename Type>
std::basic_istream<Ch, Traits> &
one_dimensional_input(std::basic_istream<Ch, Traits> &_stream, Type &_value)
{
  fcppt::io::expect(_stream, _stream.widen('('));

  fcppt::algorithm::loop(
      fcppt::math::int_range_count<Type::static_size::value>{},
      [&_stream, &_value]<fcppt::math::size_type Index>(fcppt::tag<fcppt::math::size_constant<Index>>) {

        _stream >> fcppt::math::detail::checked_access<Index>(_value);

        fcppt::math::detail::if_not_last_index(
            fcppt::math::size_constant<Index>{},
            typename Type::static_size{},
            [&_stream] { fcppt::io::expect(_stream, _stream.widen(',')); });
      });

  fcppt::io::expect(_stream, _stream.widen(')'));

  return _stream;
}

}

#endif
