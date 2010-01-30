//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_INPUT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_INPUT_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/detail/is_dynamic.hpp>
#include <fcppt/math/detail/one_dimensional_input.hpp>
#include <boost/utility/enable_if.hpp>
#include <iosfwd>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T,
	typename N,
	typename S,
	typename Ch,
	typename Traits
>
typename boost::disable_if<
	math::detail::is_dynamic<
		N
	>,
	std::basic_istream<Ch, Traits> &
>::type
operator>> (
	std::basic_istream<Ch, Traits> &s,
	basic<T, N, S> &v)
{
	return math::detail::one_dimensional_input(
		s,
		v);
}

}
}
}

#endif
