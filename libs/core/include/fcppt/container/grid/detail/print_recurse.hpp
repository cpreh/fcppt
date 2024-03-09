//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_DETAIL_PRINT_RECURSE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_PRINT_RECURSE_HPP_INCLUDED

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/output.hpp>
#include <fcppt/container/grid/dim_type.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos_type.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/at.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::grid::detail
{
template <
    fcppt::container::grid::size_type Level,
    typename Ch,
    typename Traits,
    typename Type,
    fcppt::container::grid::size_type Size,
    typename Alloc>
void print_recurse(
    std::basic_ostream<Ch, Traits> &_stream,
    fcppt::container::grid::object<Type, Size, Alloc> const &_object,
    fcppt::container::grid::pos_type<fcppt::container::grid::object<Type, Size, Alloc>> const _pos)
  requires(Level == 0)
{
  _stream << fcppt::output(_object.get_unsafe(_pos));
}

template <
    fcppt::container::grid::size_type Level,
    typename Ch,
    typename Traits,
    typename Type,
    fcppt::container::grid::size_type Size,
    typename Alloc>
void print_recurse(
    std::basic_ostream<Ch, Traits> &_stream,
    fcppt::container::grid::object<Type, Size, Alloc> const &_object,
    fcppt::container::grid::pos_type<fcppt::container::grid::object<Type, Size, Alloc>> _pos)
requires(Level != 0)
{
  constexpr size_type const index(Level - 1U);

  _stream << _stream.widen('(');

  using dim_value_type = fcppt::type_traits::value_type<
      fcppt::container::grid::dim_type<fcppt::container::grid::object<Type, Size, Alloc>>>;

  dim_value_type const sz{fcppt::math::dim::at<index>(_object.size())};

  for (dim_value_type const i : fcppt::make_int_range_count(sz))
  {
    fcppt::math::vector::at<index>(_pos) = i;

    fcppt::container::grid::detail::print_recurse<index>(_stream, _object, _pos);

    if (i < sz - 1U)
    {
      _stream << _stream.widen(',');
    }
  }

  _stream << _stream.widen(')');
}

}

#endif
