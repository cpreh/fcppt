//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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

/// Outputs a matrix to a basic_ostream
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
	basic<T, N, M, S> const &m
)
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
