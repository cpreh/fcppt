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


#ifndef FCPPT_MATH_MATRIX_DETAIL_TYPEDEF_HELPER_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_TYPEDEF_HELPER_HPP_INCLUDED

#include <fcppt/math/matrix/basic_fwd.hpp>
#include <fcppt/math/detail/array_adapter.hpp>
#include <fcppt/math/detail/view_storage.hpp>
#include <fcppt/math/vector/basic_decl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	typename T,
	typename N,
	typename M,
	typename S
>
class typedef_helper {
public:
	typedef math::detail::array_adapter<
		basic<
			T,
			N,
			M,
			S
		>,
		T,
		typename N::value_type,
		vector::basic<
			T,
			N,
			math::detail::view_storage<
				T,
				N
			>
		>,
		vector::basic<
			T,
			N,
			math::detail::view_storage<
				T const,
				N
			>
		>
	> type;
};

}
}
}
}

#endif
