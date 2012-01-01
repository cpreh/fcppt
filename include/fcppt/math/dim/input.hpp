//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_INPUT_HPP_INCLUDED
#define FCPPT_MATH_DIM_INPUT_HPP_INCLUDED

#include <fcppt/math/is_dynamic_size.hpp>
#include <fcppt/math/detail/one_dimensional_input.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Reads a dim from \p s, expecting it in the format

<pre>(a_1,a_2,...)</pre>

where <code>a_i</code> are the components
\ingroup fcpptmathdim
*/
template<
	typename T,
	typename N,
	typename S,
	typename Ch,
	typename Traits
>
typename boost::disable_if<
	math::is_dynamic_size<
		N
	>,
	std::basic_istream<Ch, Traits> &
>::type
operator >> (
	std::basic_istream<Ch, Traits> &s,
	basic<T, N, S> &v
)
{
	return
		math::detail::one_dimensional_input(
			s,
			v
		);
}

}
}
}

#endif
