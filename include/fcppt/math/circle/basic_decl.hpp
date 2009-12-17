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


#ifndef FCPPT_MATH_CIRCLE_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_CIRCLE_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/circle/basic_fwd.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/basic_decl.hpp>

namespace fcppt
{
namespace math
{
namespace circle
{

template<
	typename T
>
class basic {
public:
	typedef T value_type;
	typedef T &reference;
	typedef T const &const_reference;

	typedef typename vector::static_<
		value_type,
		2
	>::type point_type;

	basic(
		point_type const &origin,
		const_reference radius);

	point_type &origin();
	point_type const &origin() const;
	reference radius();
	const_reference radius() const;
private:
	point_type origin_;
	value_type radius_;
};

}
}
}

#endif
