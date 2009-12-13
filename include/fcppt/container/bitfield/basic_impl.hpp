/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_CONTAINER_BITFIELD_BASIC_IMPL_HPP_INCLUDED
#define SGE_CONTAINER_BITFIELD_BASIC_IMPL_HPP_INCLUDED

#include <sge/container/bitfield/basic_decl.hpp>
#include <sge/container/bitfield/iterator_impl.hpp>
#include <sge/container/bitfield/proxy_impl.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/operator/bitwise.hpp>
#include <algorithm>

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
sge::container::bitfield::basic<Enum, Size, InternalType>::basic()
:
	array()
{}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
sge::container::bitfield::basic<Enum, Size, InternalType>::basic(
	Enum const e)
:
	array()
{
	set(e, true);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
sge::container::bitfield::basic<Enum, Size, InternalType> &
sge::container::bitfield::basic<Enum, Size, InternalType>::operator=(
	Enum const e)
{
	clear();
	set(e, true);
	return *this;
}

template<typename Enum, Enum Size, typename InternalType>
typename sge::container::bitfield::basic<Enum, Size, InternalType>::iterator
sge::container::bitfield::basic<Enum, Size, InternalType>::begin()
{
	return iterator(
		array,
		0
	);
}

template<typename Enum, Enum Size, typename InternalType>
typename sge::container::bitfield::basic<Enum, Size, InternalType>::const_iterator
sge::container::bitfield::basic<Enum, Size, InternalType>::begin() const
{
	return const_iterator(
		array,
		0
	);
}

template<typename Enum, Enum Size, typename InternalType>
typename sge::container::bitfield::basic<Enum, Size, InternalType>::iterator
sge::container::bitfield::basic<Enum, Size, InternalType>::end()
{
	return iterator(array, size());
}

template<typename Enum, Enum Size, typename InternalType>
typename sge::container::bitfield::basic<Enum, Size, InternalType>::const_iterator
sge::container::bitfield::basic<Enum, Size, InternalType>::end() const
{
	return const_iterator(array, size());
}

template<typename Enum, Enum Size, typename InternalType>
typename sge::container::bitfield::basic<Enum, Size, InternalType>::reverse_iterator
sge::container::bitfield::basic<Enum, Size, InternalType>::rbegin()
{
	return reverse_iterator(end());
}

template<typename Enum, Enum Size, typename InternalType>
typename sge::container::bitfield::basic<Enum, Size, InternalType>::const_reverse_iterator
sge::container::bitfield::basic<Enum, Size, InternalType>::rbegin() const
{
	return const_reverse_iterator(end());
}

template<typename Enum, Enum Size, typename InternalType>
typename sge::container::bitfield::basic<Enum, Size, InternalType>::reverse_iterator
sge::container::bitfield::basic<Enum, Size, InternalType>::rend()
{
	return reverse_iterator(begin());
}

template<typename Enum, Enum Size, typename InternalType>
typename sge::container::bitfield::basic<Enum, Size, InternalType>::const_reverse_iterator
sge::container::bitfield::basic<Enum, Size, InternalType>::rend() const
{
	return const_reverse_iterator(begin());
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
typename sge::container::bitfield::size_type
sge::container::bitfield::basic<
	Enum,
	Size,
	InternalType
>::size() const
{
	return Size;
}

template<typename Enum, Enum Size, typename InternalType>
typename sge::container::bitfield::basic<Enum, Size, InternalType>::const_reference
sge::container::bitfield::basic<Enum, Size, InternalType>::operator[](
	Enum const index) const
{
	return *(begin() + index);
}

template<typename Enum, Enum Size, typename InternalType>
typename sge::container::bitfield::basic<Enum, Size, InternalType>::reference
sge::container::bitfield::basic<Enum, Size, InternalType>::operator[](
	Enum const index)
{
	return *(begin() + index);
}

template<typename Enum, Enum Size, typename InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>&
sge::container::bitfield::basic<Enum, Size, InternalType>::operator|=(
	Enum const e)
{
	set(e, true);
	return *this;
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
sge::container::bitfield::basic<Enum, Size, InternalType> &
sge::container::bitfield::basic<Enum, Size, InternalType>::operator|=(
	basic<Enum, Size, InternalType> const &r)
{
	namespace args = boost::phoenix::arg_names;

	std::transform(
		array.begin(),
		array.end(),
		r.array.begin(),
		array.begin(),
		args::arg1 | args::arg2
	);
	return *this;
}

template<typename Enum, Enum Size, typename InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>::operator|(
	Enum const r) const
{
	basic ret(*this);
	ret.set(r, true);
	return ret;
}

template<typename Enum, Enum Size, typename InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>::operator|(
	basic<Enum, Size, InternalType> const &r) const
{
	basic ret(*this);
	ret |= r;
	return ret;
}

template<typename Enum, Enum Size, typename InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>&
sge::container::bitfield::basic<Enum, Size, InternalType>::operator&=(
	basic<Enum, Size, InternalType> const &r)
{
	namespace args = boost::phoenix::arg_names;

	std::transform(
		array.begin(),
		array.end(),
		r.array.begin(),
		array.begin(),
		args::arg1 & args::arg2
	);
	return *this;
}

template<typename Enum, Enum Size, typename InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>::operator& (
	basic<Enum, Size, InternalType> const &r) const
{
	basic ret(*this);
	ret &= r;
	return ret;
}

template<typename Enum, Enum Size, typename InternalType>
sge::container::bitfield::value_type
sge::container::bitfield::basic<Enum, Size, InternalType>::operator& (
	Enum const where) const
{
	return get(where);
}

template<typename Enum, Enum Size, typename InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>&
sge::container::bitfield::basic<Enum, Size, InternalType>::operator^=(
	basic<Enum, Size, InternalType> const &r)
{
	namespace args = boost::phoenix::arg_names;

	std::transform(
		array.begin(),
		array.end(),
		r.array.begin(),
		array.begin(),
		args::arg1 ^ args::arg2
	);
	return *this;
}

template<typename Enum, Enum Size, typename InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>::operator^(
	basic<Enum, Size, InternalType> const &r) const
{
	basic ret(*this);
	ret ^= r;
	return ret;
}

template<typename Enum, Enum Size, typename InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>
sge::container::bitfield::basic<Enum, Size, InternalType>::operator~() const
{
	namespace args = boost::phoenix::arg_names;

	basic ret(*this);

	std::transform(
		ret.array.begin(),
		ret.array.end(),
		ret.array.begin(),
		~args::arg1
	);

	return ret;
}

template<typename Enum, Enum Size, typename InternalType>
void sge::container::bitfield::basic<Enum, Size, InternalType>::set(
	Enum const where,
	value_type const value)
{
	(*this)[where] = value;
}

template<typename Enum, Enum Size, typename InternalType>
sge::container::bitfield::value_type
sge::container::bitfield::basic<Enum, Size, InternalType>::get(
	Enum const where) const
{
	return (*this)[where];
}

template<typename Enum, Enum Size, typename InternalType>
void sge::container::bitfield::basic<Enum, Size, InternalType>::clear()
{
	array.assign(0);
}

template<typename Enum, Enum Size, typename InternalType>
bool sge::container::bitfield::basic<Enum, Size, InternalType>::operator==(
	basic<Enum, Size, InternalType> const &r) const
{
	return std::equal(begin(), end(), r.begin());
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
sge::container::bitfield::basic<Enum, Size, InternalType>::operator!=(
	basic<Enum, Size, InternalType> const &r) const
{
	return !((*this)==r);
}

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
bool
sge::container::bitfield::basic<Enum, Size, InternalType>::boolean_test() const
{
	for (const_iterator i = begin(); i != end(); ++i)
		if (*i)
			return true;
	return false;
}

#endif
