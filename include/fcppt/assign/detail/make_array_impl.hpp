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


#ifndef SGE_ASSIGN_DETAIL_MAKE_ARRAY_IMPL_HPP_INCLUDED
#define SGE_ASSIGN_DETAIL_MAKE_ARRAY_IMPL_HPP_INCLUDED

#include <algorithm>

template<
	class T,
	std::size_t N>
sge::assign::detail::array<T,N>::array(
	T const &t)
{
	a[0] = t;
}

template<
	class T,
	std::size_t N>
sge::assign::detail::array<T,N>::array(
	array<T,N-1> const &that,
	T const &t)
{
	std::copy(
		that.a.begin(),
		that.a.end(),
		a.begin());

	a.back() = t;
}

template<
	class T,
	std::size_t N>
sge::assign::detail::array<T,N+1>
sge::assign::detail::array<T,N>::operator()(
	T const &t)
{
	return array<T,N+1>(
		*this,
		t);
}

template<
	class T,
	std::size_t N>
sge::assign::detail::array<T,N>::operator container_type() const
{
	return a;
}

template<typename T>
sge::assign::detail::array<T,1> sge::assign::make_array(
	T const &t)
{
	return detail::array<T,1>(
		t);
}

#endif
