//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_OFFSET_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OFFSET_HPP_INCLUDED

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep
#include <fcppt/tag.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/int_range.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/at.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::grid
{
/**
\brief Returns the absolute offset of a position

\ingroup fcpptcontainergrid
*/
template <typename SizeType, fcppt::container::grid::size_type Size>
SizeType offset(
    fcppt::container::grid::pos<SizeType, Size> const &_pos,
    fcppt::container::grid::dim<SizeType, Size> const &_size)
{
  FCPPT_DECLARE_STRONG_TYPEDEF(SizeType, result);

  FCPPT_DECLARE_STRONG_TYPEDEF(SizeType, stacked_dim);

  return fcppt::algorithm::fold(
             fcppt::math::int_range<1U, Size>{},
             std::make_pair(result{_pos.x()}, stacked_dim{fcppt::literal<SizeType>(1)}),
             [&_pos, &_size]<fcppt::math::size_type Index>(
                 fcppt::tag<fcppt::math::size_constant<Index>>, std::pair<result, stacked_dim> _sum)
             {
               _sum.second *= stacked_dim{fcppt::math::dim::at<Index - 1U>(_size)};

               _sum.first += result{fcppt::math::vector::at<Index>(_pos) * _sum.second.get()};

               return _sum;
             })
      .first.get();
}
}

#endif
