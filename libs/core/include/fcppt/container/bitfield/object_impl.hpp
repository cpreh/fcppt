//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BITFIELD_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init.hpp>
#include <fcppt/container/bitfield/object_decl.hpp> // IWYU pragma: export
#include <fcppt/container/bitfield/proxy_impl.hpp> // IWYU pragma: keep
#include <fcppt/container/bitfield/value_type.hpp>
#include <fcppt/container/bitfield/detail/null_array.hpp>

template <typename ElementType, typename InternalType>
fcppt::container::bitfield::object<ElementType, InternalType>::object(
    fcppt::no_init const &)
// Don't initialize array_
{
}

template <typename ElementType, typename InternalType>
fcppt::container::bitfield::object<ElementType, InternalType>::object(
    initializer_list_type const &_init)
    : array_(fcppt::container::bitfield::detail::null_array<array_type>())
{
  for (auto const &elem : _init)
  {
    this->set(elem, true);
  }
}

template <typename ElementType, typename InternalType>
fcppt::container::bitfield::object<ElementType, InternalType>::object(
    array_type const &_array)
    : array_(_array)
{
}

template <typename ElementType, typename InternalType>
typename fcppt::container::bitfield::object<ElementType, InternalType>::const_reference
fcppt::container::bitfield::object<ElementType, InternalType>::operator[](
    ElementType const _index) const
{
  return const_reference{this->array_, object::to_index(_index)};
}

template <typename ElementType, typename InternalType>
typename fcppt::container::bitfield::object<ElementType, InternalType>::reference
fcppt::container::bitfield::object<ElementType, InternalType>::operator[](
    ElementType const _index)
{
  return reference{this->array_, object::to_index(_index)};
}

template <typename ElementType, typename InternalType>
void fcppt::container::bitfield::object<ElementType, InternalType>::set(
    ElementType const _index, value_type const _value)
{
  (*this)[_index] = _value;
}

template <typename ElementType, typename InternalType>
fcppt::container::bitfield::value_type
fcppt::container::bitfield::object<ElementType, InternalType>::get(
    ElementType const _index) const
{
  return (*this)[_index];
}

template <typename ElementType, typename InternalType>
typename fcppt::container::bitfield::object<ElementType, InternalType>::array_type &
fcppt::container::bitfield::object<ElementType, InternalType>::array()
{
  return array_;
}

template <typename ElementType, typename InternalType>
typename fcppt::container::bitfield::object<ElementType, InternalType>::
    array_type const &
    fcppt::container::bitfield::object<ElementType, InternalType>::array() const
{
  return array_;
}

template <typename ElementType, typename InternalType>
fcppt::container::bitfield::object<ElementType, InternalType>
fcppt::container::bitfield::object<ElementType, InternalType>::null()
{
  return object(fcppt::container::bitfield::detail::null_array<array_type>());
}

template <typename ElementType, typename InternalType>
typename fcppt::container::bitfield::object<ElementType, InternalType>::size_type
fcppt::container::bitfield::object<ElementType, InternalType>::to_index(
    ElementType const _index)
{
  return static_cast<size_type>(_index);
}

#endif
