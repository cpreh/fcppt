//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OUTPUT_HPP_INCLUDED

#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Outputs the matrix to a <code>basic_ostream</code>
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam M The matrix's row dimension type
\tparam N The matrix's column dimension type
\tparam S The matrix's storage type
\tparam Ch The stream's character type
\tparam Traits The stream's character traits type

The format will contain no new-lines and will be of the form:

<pre>
((a,b,c,...),(d,e,f,...),...,...)
</pre>

So it'll be the same as if you output the column vectors using the according
<code>operator<<</code>.
*/
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
	object<T, N, M, S> const &m
)
{
	typedef typename object<T, N, M, S>::size_type size_type;

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
