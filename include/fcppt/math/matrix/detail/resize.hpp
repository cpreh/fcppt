//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_RESIZE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_RESIZE_HPP_INCLUDED

#include <fcppt/math/matrix/detail/dim_storage.hpp>
#include <fcppt/math/matrix/detail/dynamic_dim.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	typename Dim,
	typename N,
	typename M,
	typename S
>
void resize(
	Dim const &,
	dim_storage<
		N,
		M
	> &,
	S const &)
{}

template<
	typename Dim,
	typename S
>
void resize(
	Dim const &d,
	dynamic_dim &dim,
	S &store)
{
	dim.columns(d.w());
	dim.rows(d.h());

	store.resize(
		d.w() * d.h()
	);
}

}
}
}
}

#endif
