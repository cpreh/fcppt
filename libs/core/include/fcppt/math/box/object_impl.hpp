//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_BOX_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_decl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/dim.hpp>
#include <fcppt/math/vector/to_dim.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T, fcppt::math::size_type N>
fcppt::math::box::object<T, N>::object(fcppt::no_init const &_no_init)
    : min_{_no_init}, max_{_no_init}
{
}

template <typename T, fcppt::math::size_type N>
fcppt::math::box::object<T, N>::object(vector const _pos, dim const _size)
    : min_{_pos}, max_{_pos + _size}
{
}

template <typename T, fcppt::math::size_type N>
fcppt::math::box::object<T, N>::object(min_t _min, max_t _max)
    : min_{std::move(_min.get())}, max_{std::move(_max.get())}
{
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::vector &fcppt::math::box::object<T, N>::pos()
{
  return this->min_;
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::vector const &fcppt::math::box::object<T, N>::pos() const
{
  return this->min_;
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::vector &fcppt::math::box::object<T, N>::min()
{
  return this->min_;
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::vector const &fcppt::math::box::object<T, N>::min() const
{
  return this->min_;
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::vector &fcppt::math::box::object<T, N>::max()
{
  return this->max_;
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::vector const &fcppt::math::box::object<T, N>::max() const
{
  return this->max_;
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::dim fcppt::math::box::object<T, N>::size() const
{
  return fcppt::math::vector::to_dim(this->max_ - this->min_);
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::value_type fcppt::math::box::object<T, N>::left() const
{
  return this->min_.x();
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::value_type fcppt::math::box::object<T, N>::right() const
{
  return this->max_.x();
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::value_type fcppt::math::box::object<T, N>::top() const
{
  return this->min_.y();
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::value_type fcppt::math::box::object<T, N>::bottom() const
{
  return this->max_.y();
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::value_type fcppt::math::box::object<T, N>::front() const
{
  return this->min_.z();
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::box::object<T, N>::value_type fcppt::math::box::object<T, N>::back() const
{
  return this->max_.z();
}

#endif
