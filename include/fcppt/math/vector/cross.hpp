//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_CROSS_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_CROSS_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/normal_storage.hpp>
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
	typename S1,
	typename S2
>
typename boost::enable_if<
	math::detail::has_size<
		N,
		3
	>,
	basic<
		T,
		N,
		typename normal_storage<
			T,
			N
		>::type
	> const
>::type
cross(
	basic<T, N, S1> const &l,
	basic<T, N, S2> const &r
)
{
	return
		basic<
			T,
			N,
			typename normal_storage<
				T,
				N
			>::type
		>(
			l.y() * r.z() - l.z() * r.y(),
			l.z() * r.x() - l.x() * r.z(),
			l.x() * r.y() - l.y() * r.x()
		);
}

}
}
}

#endif
