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


#ifndef FCPPT_MATH_MATRIX_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OUTPUT_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <ostream>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	typename N,
	typename M,
	typename S,
	typename Ch,
	typename Traits
>
std::basic_ostream<Ch,Traits> &
operator<< (
	std::basic_ostream<Ch,Traits> &s,
	basic<T, N, M, S> const &m)
{
	typedef typename basic<T, N, M, S>::size_type size_type;

	s << s.widen('(');
	for(size_type j = 0; j < m.rows(); ++j)
	{
		s << s.widen('(');
		for(size_type i = 0; i < m.columns(); ++i)
		{
			s << m[j][i];
			if(i != m.columns() - 1)
				s << s.widen(',');
		}
		s << s.widen(')');
		if(j != m.rows() - 1)
			s << s.widen(',');
	}
	return s << s.widen(')');
}

}
}
}

#endif
