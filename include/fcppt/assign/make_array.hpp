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


#ifndef SGE_ASSIGN_MAKE_ARRAY_HPP_INCLUDED
#define SGE_ASSIGN_MAKE_ARRAY_HPP_INCLUDED

#include <tr1/array>
#include <cstddef>

namespace sge
{
namespace assign
{
namespace detail
{
template<
	class T,
	std::size_t N>
class array
{
public:
	typedef std::tr1::array<T,N> container_type;

	array(
		T const &);

	array(
		array<T,N-1> const &,
		T const &);

	array<T,N+1> operator()(T const &);

	operator container_type() const;
private:
	friend class array<T,N+1>;

	container_type a;
};
}

template<typename T>
detail::array<T,1> make_array(T const &);
}
}

#include <sge/assign/detail/make_array_impl.hpp>

#endif
