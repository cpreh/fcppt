//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BITFIELD_PROXY_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_PROXY_IMPL_HPP_INCLUDED

#include <fcppt/bit/mask_impl.hpp> // IWYU pragma: keep
#include <fcppt/bit/shift_count.hpp>
#include <fcppt/bit/shifted_mask.hpp>
#include <fcppt/bit/test.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/container/bitfield/proxy_decl.hpp> // IWYU pragma: export
#include <fcppt/container/bitfield/value_type.hpp>

template <typename StoredType>
fcppt::container::bitfield::proxy<StoredType>::proxy(StoredType &_array, size_type const _pos)
    : array_(_array), pos_(_pos)
{
}

template <typename StoredType>
typename fcppt::container::bitfield::proxy<StoredType>::size_type
fcppt::container::bitfield::proxy<StoredType>::bit_offset(size_type const _pos)
{
  return _pos % element_bits;
}

template <typename StoredType>
typename fcppt::container::bitfield::proxy<StoredType>::size_type
fcppt::container::bitfield::proxy<StoredType>::array_offset(size_type const _pos)
{
  return _pos / element_bits;
}

template <typename StoredType>
typename fcppt::container::bitfield::proxy<StoredType>::mask_type
fcppt::container::bitfield::proxy<StoredType>::bit_mask(size_type const _pos)
{
  return fcppt::bit::shifted_mask<internal_type>(fcppt::cast::size<fcppt::bit::shift_count>(_pos));
}

template <typename StoredType>
fcppt::container::bitfield::proxy<StoredType>::proxy(proxy const &) = default;

template <typename StoredType>
fcppt::container::bitfield::proxy<StoredType>::proxy(proxy &&) noexcept = default;

template <typename StoredType>
fcppt::container::bitfield::proxy<StoredType> &
fcppt::container::bitfield::proxy<StoredType>::operator=(proxy const &) = default;

template <typename StoredType>
fcppt::container::bitfield::proxy<StoredType> &
fcppt::container::bitfield::proxy<StoredType>::operator=(proxy &&) noexcept = default;

namespace fcppt::container::bitfield
{
template <typename StoredType>
proxy<StoredType>::~proxy() = default;
}

template <typename StoredType>
fcppt::container::bitfield::proxy<StoredType> &
fcppt::container::bitfield::proxy<StoredType>::operator=(
    fcppt::container::bitfield::value_type const _value)
{
  size_type const index(this->array_offset(pos_));

  size_type const bit(this->bit_offset(pos_));

  mask_type const mask(this->bit_mask(bit));

  if (_value)
  {
    array_->get_unsafe(index) |= mask.get();
  }
  else
  {
    array_->get_unsafe(index) &= static_cast<internal_type>(~mask.get());
  }

  return *this;
}

template <typename StoredType>
fcppt::container::bitfield::proxy<StoredType>::operator fcppt::container::bitfield::value_type()
    const
{
  return fcppt::bit::test(
      array_->get_unsafe(this->array_offset(pos_)), this->bit_mask(this->bit_offset(pos_)));
}

#endif
