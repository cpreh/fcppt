//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_LENGTH_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_LENGTH_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/length_square.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>

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
typename boost::enable_if<
	boost::is_floating_point<T>,
	typename basic<T, N, S>::value_type
>::type
length(
	basic<T, N, S> const &v
)
{
	return std::sqrt(
		length_square(
			v
		)
	);
}

template<
	typename Dest,
	typename T,
	typename N,
	typename S
>
typename boost::disable_if<
	boost::is_floating_point<T>,
	Dest
>::type
length(
	basic<T, N, S> const &v
)
{
	return std::sqrt(
		static_cast<Dest>(
			length_square(
				v
			)
		)
	);
}

}
}
}

#endif
