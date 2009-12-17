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


#ifndef FCPPT_MATH_MATRIX_DETAIL_DIM_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_DIM_STORAGE_HPP_INCLUDED

#include <fcppt/math/detail/dynamic_size.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	typename N,
	typename M
>
class dim_storage {
public:
	typedef typename N::value_type size_type;

	size_type columns() const
	{
		return N::value;
	}

	size_type rows() const
	{
		return M::value;
	}
};

template<>
class dim_storage<
	math::detail::dynamic_size,
	math::detail::dynamic_size
> {
public:
	typedef math::detail::dynamic_size::value_type size_type;

	size_type columns() const
	{
		return columns_;
	}

	size_type rows() const
	{
		return rows_;
	}

	void columns(
		size_type const ncolumns)
	{
		columns_ = ncolumns;
	}

	void rows(
		size_type const nrows)
	{
		rows_ = nrows;
	}

private:
	size_type
		columns_,
		rows_;
};

}
}
}
}

#endif
