//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ANGLE_BETWEEN_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ANGLE_BETWEEN_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/atan2.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/math/detail/has_size.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/mpl/and.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename Dest,
	typename T,
	typename N,
	typename S
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_floating_point<
			Dest
		>,
		math::detail::has_size<
			N,
			2
		>
	>,
	optional<Dest>
>::type
angle_between(
	basic<T, N, S> const &from,
	basic<T, N, S> const &to)
{
	return atan2(
		structure_cast<
			typename static_<
				Dest,
				N::value
			>::type
		>(
			to - from
		)
	);
}

}
}
}

#endif
