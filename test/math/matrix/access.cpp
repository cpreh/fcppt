//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/homogenous_pair.hpp>
#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/matrix/init.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::matrix access",
	"[math],[matrix]"
)
{
	using
	matrix_type
	=
	fcppt::math::matrix::static_<
		fcppt::homogenous_pair<
			fcppt::math::size_type
		>,
		4,
		4
	>;

	auto const mat(
		fcppt::math::matrix::init<
			matrix_type
		>(
			[](
				auto const _index
			)
			{
				return
					fcppt::make_homogenous_pair(
						_index.row(),
						_index.column()
					);
			}
		)
	);

	matrix_type mat_nc{
		mat
	};

	// Row 0
	CHECK(
		mat.m00()
		==
		fcppt::make_homogenous_pair(
			0U,
			0U
		)
	);

	CHECK(
		mat.m01()
		==
		fcppt::make_homogenous_pair(
			0U,
			1U
		)
	);

	CHECK(
		mat.m02()
		==
		fcppt::make_homogenous_pair(
			0U,
			2U
		)
	);

	CHECK(
		mat.m03()
		==
		fcppt::make_homogenous_pair(
			0U,
			3U
		)
	);


	CHECK(
		mat_nc.m00()
		==
		fcppt::make_homogenous_pair(
			0U,
			0U
		)
	);

	CHECK(
		mat_nc.m01()
		==
		fcppt::make_homogenous_pair(
			0U,
			1U
		)
	);

	CHECK(
		mat_nc.m02()
		==
		fcppt::make_homogenous_pair(
			0U,
			2U
		)
	);

	CHECK(
		mat_nc.m03()
		==
		fcppt::make_homogenous_pair(
			0U,
			3U
		)
	);

	// Row 1
	CHECK(
		mat.m10()
		==
		fcppt::make_homogenous_pair(
			1U,
			0U
		)
	);

	CHECK(
		mat.m11()
		==
		fcppt::make_homogenous_pair(
			1U,
			1U
		)
	);

	CHECK(
		mat.m12()
		==
		fcppt::make_homogenous_pair(
			1U,
			2U
		)
	);

	CHECK(
		mat.m13()
		==
		fcppt::make_homogenous_pair(
			1U,
			3U
		)
	);


	CHECK(
		mat_nc.m10()
		==
		fcppt::make_homogenous_pair(
			1U,
			0U
		)
	);

	CHECK(
		mat_nc.m11()
		==
		fcppt::make_homogenous_pair(
			1U,
			1U
		)
	);

	CHECK(
		mat_nc.m12()
		==
		fcppt::make_homogenous_pair(
			1U,
			2U
		)
	);

	CHECK(
		mat_nc.m13()
		==
		fcppt::make_homogenous_pair(
			1U,
			3U
		)
	);

	// Row 2
	CHECK(
		mat.m20()
		==
		fcppt::make_homogenous_pair(
			2U,
			0U
		)
	);

	CHECK(
		mat.m21()
		==
		fcppt::make_homogenous_pair(
			2U,
			1U
		)
	);

	CHECK(
		mat.m22()
		==
		fcppt::make_homogenous_pair(
			2U,
			2U
		)
	);

	CHECK(
		mat.m23()
		==
		fcppt::make_homogenous_pair(
			2U,
			3U
		)
	);


	CHECK(
		mat_nc.m20()
		==
		fcppt::make_homogenous_pair(
			2U,
			0U
		)
	);

	CHECK(
		mat_nc.m21()
		==
		fcppt::make_homogenous_pair(
			2U,
			1U
		)
	);

	CHECK(
		mat_nc.m22()
		==
		fcppt::make_homogenous_pair(
			2U,
			2U
		)
	);

	CHECK(
		mat_nc.m23()
		==
		fcppt::make_homogenous_pair(
			2U,
			3U
		)
	);

	// Row 3
	CHECK(
		mat.m30()
		==
		fcppt::make_homogenous_pair(
			3U,
			0U
		)
	);

	CHECK(
		mat.m31()
		==
		fcppt::make_homogenous_pair(
			3U,
			1U
		)
	);

	CHECK(
		mat.m32()
		==
		fcppt::make_homogenous_pair(
			3U,
			2U
		)
	);

	CHECK(
		mat.m33()
		==
		fcppt::make_homogenous_pair(
			3U,
			3U
		)
	);


	CHECK(
		mat_nc.m30()
		==
		fcppt::make_homogenous_pair(
			3U,
			0U
		)
	);

	CHECK(
		mat_nc.m31()
		==
		fcppt::make_homogenous_pair(
			3U,
			1U
		)
	);

	CHECK(
		mat_nc.m32()
		==
		fcppt::make_homogenous_pair(
			3U,
			2U
		)
	);

	CHECK(
		mat_nc.m33()
		==
		fcppt::make_homogenous_pair(
			3U,
			3U
		)
	);
}
