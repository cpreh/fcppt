//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/matrix/detail/is_static_size.hpp>
#include <fcppt/math/detail/structure_cast_fun.hpp>
#include <fcppt/math/detail/structure_cast.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	typename Dest,
	typename T,
	typename N,
	typename M,
	typename S
>
typename boost::enable_if<
	detail::is_static_size<
		N,
		M
	>,
	Dest const
>::type
structure_cast(
	basic<T, N, M, S> const &src
)
{
	return
		math::detail::structure_cast<
			Dest
		>(
			src
		);
}

template<
	typename Dest,
	typename T,
	typename N,
	typename M,
	typename S
>
typename boost::disable_if<
	detail::is_static_size<
		N,
		M
	>,
	Dest const
>::type
structure_cast(
	basic<T, N, M, S> const &src
)
{
	typedef math::detail::structure_cast_fun<
		T
	> op_type;

	op_type const op = {};

	return
		T(
			src.dimension(),
			boost::make_transform_iterator(
				u.begin(),
				op
			),
			boost::make_transform_iterator(
				u.end(),
				op
			)
		);
}

}
}
}
}

#endif
