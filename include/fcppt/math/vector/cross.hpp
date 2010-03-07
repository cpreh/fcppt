//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_CROSS_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_CROSS_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/detail/has_size.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Calculates the cross product of two three-dimensional vectors
template<
	typename T,
	typename N,
	typename S
>
typename boost::enable_if<
	math::detail::has_size<
		N,
		3
	>,
	basic<T, N, S> const
>::type
cross(
	basic<T, N, S> const &l,
	basic<T, N, S> const &r
)
{
	return basic<T, N, S>(
		l.y() * r.z() - l.z() * r.y(),
		l.z() * r.x() - l.x() * r.z(),
		l.x() * r.y() - l.y() * r.x()
	);
}

/// Calculates the cross product of two two-dimensional vectors
template<
	typename T,
	typename N,
	typename S
>
typename boost::enable_if<
	math::detail::has_size<
		N,
		2
	>,
	T
>::type
cross(
	basic<T, N, S> const &l,
	basic<T, N, S> const &r
)
{
	return l.x() * r.y() - l.y() * r.x();
}

}
}
}

#endif
