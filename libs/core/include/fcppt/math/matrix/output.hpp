//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OUTPUT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/one_dimensional_output.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
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
	fcppt::math::size_type R,
	fcppt::math::size_type C,
	typename S,
	typename Ch,
	typename Traits
>
inline
std::basic_ostream<
	Ch,
	Traits
> &
operator<< (
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::math::matrix::object<
		T,
		R,
		C,
		S
	> const &_matrix
)
{
	return
		fcppt::math::detail::one_dimensional_output(
			_stream,
			_matrix
		);
}

}
}
}

#endif
