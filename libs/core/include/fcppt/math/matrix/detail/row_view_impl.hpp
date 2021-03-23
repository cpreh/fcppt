//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_DETAIL_ROW_VIEW_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_ROW_VIEW_IMPL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/detail/row_view_decl.hpp>

template <typename T, fcppt::math::size_type C, typename S>
fcppt::math::matrix::detail::row_view<T, C, S>::row_view(
    S &_impl, size_type const _index, size_type const _columns)
    : impl_{_impl}, offset_{_index * _columns}
{
}

template <typename T, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::detail::row_view<T, C, S>::const_reference
fcppt::math::matrix::detail::row_view<T, C, S>::operator[](size_type const _index) const
{
  return impl_.get()[offset_ + _index];
}

#endif
