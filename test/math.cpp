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



#include <fcppt/math/vector/vector.hpp>
#include <fcppt/math/matrix/matrix.hpp>
#include <fcppt/math/matrix/dynamic_impl.hpp>
#include <fcppt/math/dim/dim.hpp>
#include <fcppt/math/point_rotate.hpp>
#include <fcppt/math/box/box.hpp>
#include <fcppt/math/box/rect.hpp>	
#include <fcppt/io/cout.hpp>
#include <boost/assign/list_of.hpp>
#include <istream>
#include <ostream>

int main()
{
	fcppt::math::vector::static_<
		int,
		2
	>::type vec(
		1,
		2);

	fcppt::math::vector::angle_between<float>(
		vec,
		vec);

	typedef fcppt::math::vector::static_<
		float,
		2
	>::type vec2f;

	vec2f const vecf(
		1.f,
		2.f
	);

	fcppt::math::vector::atan2(vecf);

	fcppt::math::point_rotate(
		vecf,
		vecf,
		3.f
	);

	typedef fcppt::math::matrix::dynamic<
		float
	>::type dynamic_float_matrix;

	dynamic_float_matrix matrix(
		dynamic_float_matrix::dim_type(
			2,
			3
		),
		boost::assign::list_of
			(0.f)(0.f)
			(1.f)(1.f)
			(2.f)(2.f)
	);

	normalize(vecf);

	fcppt::io::cout
		<< vec << FCPPT_TEXT('\n')
		<< fcppt::math::vector::length<float>(vec) << FCPPT_TEXT('\n')
		<< length(vecf) << FCPPT_TEXT('\n');

	typedef fcppt::math::vector::static_<
		double,
		3
	>::type vec3d;

	{
		vec3d
			a(
				1.0,
				0.0,
				0.0
			),
			b(
				0.0,
				1.0,
				0.0
			),
			c(
				0.0,
				0.0,
				-1.0
			);

		normalize(a);
		normalize(b);
		normalize(c);

		fcppt::io::cout << cross(a, b) << FCPPT_TEXT(' ') << c << FCPPT_TEXT('\n');
	}

	vec2f const converted(
		fcppt::math::vector::narrow_cast<
			vec2f
		>(
			vec3d(
				1.0,
				2.0,
				3.0
			)
		)
	);

	fcppt::io::cout << cross(converted, converted) << FCPPT_TEXT('\n');

	fcppt::io::cout
		<< fcppt::math::vector::make(
			42,
			43,
			44
		)
		<< FCPPT_TEXT('\n');
	
	typedef fcppt::math::box::rect<
		int
	>::type int_rect;

	int_rect test_rect(
		int_rect::vector(1, 2),
		int_rect::dim(3, 2)
	);

	fcppt::io::cout
		<< test_rect
		<< FCPPT_TEXT('\n');
}
