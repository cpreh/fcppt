//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_LENGTH_QUAD_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_LENGTH_QUAD_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <boost/spirit/home/phoenix/operator/arithmetic.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <numeric>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T,
	typename N,
	typename S
>
typename basic<T, N, S>::value_type
length_quad(
	basic<T, N, S> const &v
)
{
	using boost::phoenix::arg_names::arg1;
	using boost::phoenix::arg_names::arg2;

	return
		std::accumulate(
			v.begin(),
			v.end(),
			static_cast<T>(0),
			arg1 + arg2 * arg2
		);
}

}
}
}

#endif
