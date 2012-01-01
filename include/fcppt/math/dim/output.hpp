//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_DIM_OUTPUT_HPP_INCLUDED

#include <fcppt/math/detail/one_dimensional_output.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Outputs a dim to \p s, in the format

<pre>(a_1,a_2,...)</pre>

where <code>a_i</code> are the dim's components.
\ingroup fcpptmathdim
*/
template<
	typename T,
	typename N,
	typename S,
	typename Ch,
	typename Traits
>
std::basic_ostream<Ch, Traits> &
operator<< (
	std::basic_ostream<Ch, Traits> &s,
	basic<T, N, S> const &v
)
{
	return math::detail::one_dimensional_output(
		s,
		v
	);
}

}
}
}

#endif
