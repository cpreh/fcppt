//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BITFIELD_HASH_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_HASH_IMPL_HPP_INCLUDED

#include <fcppt/container/bitfield/hash_decl.hpp>
#include <fcppt/range/hash_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

template <typename Bitfield>
std::size_t fcppt::container::bitfield::hash<Bitfield>::operator()(Bitfield const &_bitfield) const
{
  return fcppt::range::hash<typename Bitfield::array_type>()(_bitfield.array());
}

#endif
