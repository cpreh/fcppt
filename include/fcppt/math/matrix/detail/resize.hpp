/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


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
