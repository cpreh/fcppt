//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

using
mat2
=
fcppt::math::matrix::static_<
	int,
	2,
	2
>;

}

TEST_CASE(
	"math::matrix arithmetic self",
	"[math],[matrix]"
)
{
	{
		mat2 left{
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		};

		left +=
			mat2{
				fcppt::math::matrix::row(
					5,6 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				),
				fcppt::math::matrix::row(
					7,8 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				)
			};

		CHECK(
			left
			==
			mat2(
				fcppt::math::matrix::row(
					6,8 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				),
				fcppt::math::matrix::row(
					10,12 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				)
			)
		);
	}

	{
		mat2 left{
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		};

		left -=
			mat2{
				fcppt::math::matrix::row(
					2,4 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				),
				fcppt::math::matrix::row(
					1,2
				)
			};

		CHECK(
			left
			==
			mat2(
				fcppt::math::matrix::row(
					-1,-2
				),
				fcppt::math::matrix::row(
					2,2
				)
			)
		);
	}

	{
		mat2 left{
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		};

		left *=
			2; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

		CHECK(
			left
			==
			mat2(
				fcppt::math::matrix::row(
					2,4 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				),
				fcppt::math::matrix::row(
					6,8 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				)
			)
		);
	}
}


TEST_CASE(
	"math::matrix arithmetic free",
	"[math],[matrix]"
)
{
	CHECK(
		mat2(
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
		+
		mat2(
			fcppt::math::matrix::row(
				5,6 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			),
			fcppt::math::matrix::row(
				7,8 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
		==
		mat2(
			fcppt::math::matrix::row(
				6,8 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			),
			fcppt::math::matrix::row(
				10,12 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
	);

	CHECK(
		mat2(
			fcppt::math::matrix::row(
				5,6 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			),
			fcppt::math::matrix::row(
				7,8 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
		-
		mat2(
			fcppt::math::matrix::row(
				4,3 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			),
			fcppt::math::matrix::row(
				2,1
			)
		)
		==
		mat2(
			fcppt::math::matrix::row(
				1,3 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			),
			fcppt::math::matrix::row(
				5,7 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
	);

	CHECK(
		mat2(
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
		*
		2
		==
		mat2(
			fcppt::math::matrix::row(
				2,4 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			),
			fcppt::math::matrix::row(
				6,8 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
	);

	CHECK(
		2
		*
		mat2(
			fcppt::math::matrix::row(
				1,2
			),
			fcppt::math::matrix::row(
				3,4 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
		==
		mat2(
			fcppt::math::matrix::row(
				2,4 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			),
			fcppt::math::matrix::row(
				6,8 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			)
		)
	);
}
