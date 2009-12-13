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


#ifndef SGE_CONTAINER_DATA_HPP_INCLUDED
#define SGE_CONTAINER_DATA_HPP_INCLUDED

namespace sge
{
namespace container
{

// these functions may be used on vector
// (C++2003)
// and on basic_string
// (DR of 2005)

template<
	typename Container
>
typename Container::pointer
data(
	Container &c)
{
	return c.empty() ? 0 : &c[0];
}

template<
	typename Container
>
typename Container::const_pointer
data(
	Container const &c)
{
	return c.empty() ? 0 : &c[0];
}

template<
	typename Container
>
typename Container::pointer
data_end(
	Container &c)
{
	return c.empty() ? 0 : &c[0] + c.size();
}

template<
	typename Container
>
typename Container::const_pointer
data_end(
	Container const &c)
{
	return c.empty() ? 0 : &c[0] + c.size();
}

}
}

#endif
