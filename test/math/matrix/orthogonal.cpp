//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/orthogonal.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/compare.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(
	math_matrix_orthogonal
)
{
	typedef float value_type;

	typedef fcppt::math::matrix::static_<
		value_type,
		4,
		4
	>::type mat4;

	typedef fcppt::math::box::basic<
		value_type,
		2
	> box2;

	mat4 const
		proj1(
			fcppt::math::matrix::orthogonal(
				box2(
					box2::vector(
						0,
						0
					),
					box2::dim(
						1024,
						768
					)
				),
				0.f,
				1.f
			)
		),
		proj2(
			fcppt::math::matrix::orthogonal(
				0.f,
				1024.f,
				768.f,
				0.f,
				0.f,
				1.f
			)
		);

	BOOST_CHECK(
		proj1 == proj2
	);

	fcppt::io::cout
		<< proj1
		<< FCPPT_TEXT('\n');

	BOOST_CHECK(
		fcppt::math::compare(
			proj1[0][0],
			2.f / 1024.f
		)
	);

	BOOST_CHECK(
		fcppt::math::compare(
			proj1[1][1],
			-2.f / 768.f
		)
	);

	BOOST_CHECK(
		fcppt::math::compare(
			proj1[2][2],
			-2.f
		)
	);

	BOOST_CHECK(
		fcppt::math::compare(
			proj1[2][3],
			-1.f
		)
	);
}
