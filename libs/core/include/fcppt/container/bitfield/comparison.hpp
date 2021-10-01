//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BITFIELD_COMPARISON_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_COMPARISON_HPP_INCLUDED

#include <fcppt/array/comparison.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>

namespace fcppt::container::bitfield
{
/**
\brief Compares two bitfields for equality.

\ingroup fcpptcontainerbitfield
*/
template <typename ElementType, typename InternalType>
bool operator==(
    fcppt::container::bitfield::object<ElementType, InternalType> const &_left,
    fcppt::container::bitfield::object<ElementType, InternalType> const &_right)
{
  return _left.array() == _right.array();
}

/**
\brief Compares two bitfields for inequality.

\ingroup fcpptcontainerbitfield
*/
template <typename ElementType, typename InternalType>
bool operator!=(
    fcppt::container::bitfield::object<ElementType, InternalType> const &_left,
    fcppt::container::bitfield::object<ElementType, InternalType> const &_right)
{
  return !(_left == _right);
}

}

#endif
