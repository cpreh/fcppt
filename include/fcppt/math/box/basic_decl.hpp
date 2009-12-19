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


#ifndef FCPPT_MATH_BOX_BASIC_DECL_HPP_INCLUDED
#define FCPPT_MATH_BOX_BASIC_DECL_HPP_INCLUDED

#include <fcppt/math/box/basic_fwd.hpp>
#include <fcppt/math/vector/basic_decl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/dim/basic_decl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/size_type.hpp>

namespace fcppt
{
namespace math
{
namespace box
{

template<
	typename T,
	size_type N
>
class basic
{
public:
	typedef T value_type;
	typedef value_type scalar;

	typedef math::size_type size_type;

	typedef typename math::vector::static_<
		T,
		N
	>::type vector;

	typedef typename math::dim::static_<
		T,
		N
	>::type dim;

	basic();

	basic(
		vector const &,
		dim const &
	);

	static basic const
	null();

	value_type
	area() const;

	value_type
	w() const;

	value_type
	h() const;

	value_type
	d() const;

	vector const
	pos() const;

	vector const
	max() const;

	dim const
	dimension() const;

	value_type
	pos(
		size_type
	) const;

	value_type
	max(
		size_type
	) const;

	value_type
	dimension(
		size_type
	) const;

	value_type
	left() const;

	value_type
	top() const;

	value_type
	front() const;

	value_type
	right() const;

	value_type
	bottom() const;

	value_type
	back() const;

	void
	w(
		value_type
	);

	void
	h(
		value_type
	);

	void
	d(
		value_type
	);

	void
	pos(
		vector const &
	);

	void
	dimension(
		dim const &
	);

	void
	pos(
		size_type index,
		value_type
	);

	void
	dimension(
		size_type index,
		value_type
	);

	void
	left(
		value_type
	);

	void
	top(
		value_type
	);

	void
	front(
		value_type
	);

	bool
	operator==(
		basic const &
	) const;

	bool
	operator !=(
		basic const &
	) const;
private:
	vector pos_;

	dim dimension_;
};

}
}
}

#endif
