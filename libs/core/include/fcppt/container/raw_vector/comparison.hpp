//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_RAW_VECTOR_COMPARISON_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_COMPARISON_HPP_INCLUDED

#include <fcppt/container/raw_vector/object_impl.hpp>
#include <fcppt/detail/equal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::raw_vector
{
/**
\ingroup fcpptcontainerraw_vector
*/
template <typename T, typename A>
bool operator==(
    fcppt::container::raw_vector::object<T, A> const &_left,
    fcppt::container::raw_vector::object<T, A> const &_right)
{
  return _left.size() == _right.size() &&
         fcppt::detail::equal(_left.begin(), _left.end(), _right.begin());
}

/**
\ingroup fcpptcontainerraw_vector
*/
template <typename T, typename A>
bool operator<(
    fcppt::container::raw_vector::object<T, A> const &_left,
    fcppt::container::raw_vector::object<T, A> const &_right)
{
  return std::lexicographical_compare(_left.begin(), _left.end(), _right.begin(), _right.end());
}

/**
\ingroup fcpptcontainerraw_vector
*/
template <typename T, typename A>
bool operator!=(
    fcppt::container::raw_vector::object<T, A> const &_left,
    fcppt::container::raw_vector::object<T, A> const &_right)
{
  return !(_left == _right);
}

/**
\ingroup fcpptcontainerraw_vector
*/
template <typename T, typename A>
bool operator>(
    fcppt::container::raw_vector::object<T, A> const &_left,
    fcppt::container::raw_vector::object<T, A> const &_right)
{
  return _right < _left;
}

/**
\ingroup fcpptcontainerraw_vector
*/
template <typename T, typename A>
bool operator>=(
    fcppt::container::raw_vector::object<T, A> const &_left,
    fcppt::container::raw_vector::object<T, A> const &_right)
{
  return !(_left < _right);
}

/**
\ingroup fcpptcontainerraw_vector
*/
template <typename T, typename A>
bool operator<=(
    fcppt::container::raw_vector::object<T, A> const &_left,
    fcppt::container::raw_vector::object<T, A> const &_right)
{
  return !(_left > _right);
}

}

#endif
