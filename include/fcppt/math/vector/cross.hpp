//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_CROSS_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_CROSS_HPP_INCLUDED

#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/has_size.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculates the cross product of two three-dimensional vectors
\ingroup fcpptmathvector
\tparam T The vector's <code>value_type</code>
\tparam N The vector's dimension type (must be three-dimensional if it's a static vector).
\tparam S1 The first vector's storage type
\tparam S2 The first vector's storage type

The cross product is defined here:

http://en.wikipedia.org/wiki/Cross_product
*/
template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename boost::enable_if<
	fcppt::math::detail::has_size<
		N,
		3
	>,
	fcppt::math::vector::object<
		T,
		N,
		fcppt::math::static_storage<
			T,
			N
		>
	> const
>::type
cross(
	fcppt::math::vector::object<
		T,
		N,
		S1
	> const &l,
	fcppt::math::vector::object<
		T,
		N,
		S2
	> const &r
)
{
	return
		fcppt::math::vector::object<
			T,
			N,
			fcppt::math::static_storage<
				T,
				N
			>
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
