//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/math/point_rotate.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/vector/atan2.hpp>
#include <fcppt/math/vector/cross.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/normalize.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/assign/list_of.hpp>
#include <istream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
	fcppt::math::vector::static_<
		int,
		2
	>::type vec(
		1,
		2);

	typedef fcppt::math::vector::static_<
		float,
		2
	>::type vec2f;

	vec2f const vecf(
		1.f,
		2.f
	);

	fcppt::math::vector::atan2(
		vecf
	);

	fcppt::math::point_rotate(
		vecf,
		vecf,
		3.f
	);

	fcppt::math::vector::normalize(
		vecf
	);

	fcppt::io::cout()
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

		fcppt::io::cout()
			<< fcppt::math::vector::cross(a, b)
			<< FCPPT_TEXT(' ')
			<< c
			<< FCPPT_TEXT('\n');
	}

	typedef fcppt::math::box::rect<
		int
	>::type int_rect;

	int_rect test_rect(
		int_rect::vector(1, 2),
		int_rect::dim(3, 2)
	);

	fcppt::io::cout()
		<< test_rect
		<< FCPPT_TEXT('\n');
}
