//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/detail/structure_cast.hpp>
#include <fcppt/math/detail/structure_cast_fun.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/is_static_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


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
	matrix::is_static_size<
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
	matrix::is_static_size<
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
				src.begin(),
				op
			),
			boost::make_transform_iterator(
				src.end(),
				op
			)
		);
}

}
}
}
}

#endif
