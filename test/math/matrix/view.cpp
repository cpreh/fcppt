//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/at_r.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::matrix view",
	"[math],[matrix]"
)
{
	typedef
	int
	value_type;

	constexpr std::size_t const size{
		3u
	};

	typedef
	fcppt::math::matrix::static_<
		value_type,
		size,
		size
	>
	matrix_type;

	typedef
	fcppt::math::vector::static_<
		value_type,
		size
	>
	vector_type;

	matrix_type const matrix(
		fcppt::math::matrix::row(
			-3, 2, -5
		),
		fcppt::math::matrix::row(
			-1, 0, -2
		),
		fcppt::math::matrix::row(
			3, -4, 1
		)
	);

	CHECK(
		fcppt::math::matrix::at_r<
			0
		>(
			matrix
		)
		==
		vector_type(
			-3,
			2,
			-5
		)
	);

	vector_type vec(
		fcppt::math::matrix::at_r<
			0
		>(
			matrix
		)
	);

	vec =
		fcppt::math::matrix::at_r<
			1
		>(
			matrix
		);

	CHECK(
		vec
		==
		vector_type(
			-1,
			0,
			-2
		)
	);
}
