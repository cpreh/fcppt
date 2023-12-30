//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_SPHERE_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_SPHERE_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/sphere/object_decl.hpp> // IWYU pragma: export
#include <fcppt/math/vector/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T, fcppt::math::size_type N>
fcppt::math::sphere::object<T, N>::object(point_type _origin, value_type _radius)
    : origin_(std::move(_origin)), radius_(std::move(_radius))
{
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::sphere::object<T, N>::point_type &fcppt::math::sphere::object<T, N>::origin()
{
  return origin_;
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::sphere::object<T, N>::point_type const &
fcppt::math::sphere::object<T, N>::origin() const
{
  return origin_;
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::sphere::object<T, N>::reference fcppt::math::sphere::object<T, N>::radius()
{
  return radius_;
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::sphere::object<T, N>::const_reference
fcppt::math::sphere::object<T, N>::radius() const
{
  return radius_;
}

#endif
