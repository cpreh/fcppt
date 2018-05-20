//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/scaling.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::matrix::scaling",
	"[math],[matrix]"
)
{
	typedef
	fcppt::math::matrix::static_<
		int,
		4,
		4
	>
	matrix_type;

	matrix_type const trans(
		fcppt::math::matrix::scaling(
			5,
			3,
			4
		)
	);

	CHECK(
		trans
		==
		matrix_type(
			fcppt::math::matrix::row(
				5, 0, 0, 0
			),
			fcppt::math::matrix::row(
				0, 3, 0, 0
			),
			fcppt::math::matrix::row(
				0, 0, 4, 0
			),
			fcppt::math::matrix::row(
				0, 0, 0, 1
			)
		)
	);

	typedef
	fcppt::math::vector::static_<
		int,
		4
	>
	vector_type;

	vector_type const vec(
		1,
		2,
		3,
		1
	);

	CHECK(
		trans
		*
		vec
		==
		vector_type(
			5,
			6,
			12,
			1
		)
	);

}
