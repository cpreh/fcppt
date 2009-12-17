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


#ifndef FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_OUTPUT_HPP_INCLUDED

#include <ostream>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Ch,
	typename Traits,
	typename T
>
std::basic_ostream<Ch, Traits> &
one_dimensional_output(
	std::basic_ostream<Ch, Traits> &s,
	T const &v)
{
	s << s.widen('(');
	if(v.size() > 1)
		for(typename T::size_type i = 0; i < v.size() - 1; ++i)
			s << v[i] << s.widen(',');
	if(!v.empty())
		s << v.back();
	return s << s.widen(')');
}

}
}
}

#endif
