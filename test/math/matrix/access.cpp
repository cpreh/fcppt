//          Copyright Carl Philipp Reh 2009 - 2017.
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
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_matrix_access
)
{
	typedef
	fcppt::math::matrix::static_<
		fcppt::homogenous_pair<
			fcppt::math::size_type
		>,
		4,
		4
	>
	matrix_type;

	matrix_type const mat(
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
	BOOST_CHECK_EQUAL(
		mat.m00(),
		fcppt::make_homogenous_pair(
			0u,
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m01(),
		fcppt::make_homogenous_pair(
			0u,
			1u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m02(),
		fcppt::make_homogenous_pair(
			0u,
			2u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m03(),
		fcppt::make_homogenous_pair(
			0u,
			3u
		)
	);


	BOOST_CHECK_EQUAL(
		mat_nc.m00(),
		fcppt::make_homogenous_pair(
			0u,
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m01(),
		fcppt::make_homogenous_pair(
			0u,
			1u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m02(),
		fcppt::make_homogenous_pair(
			0u,
			2u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m03(),
		fcppt::make_homogenous_pair(
			0u,
			3u
		)
	);

	// Row 1
	BOOST_CHECK_EQUAL(
		mat.m10(),
		fcppt::make_homogenous_pair(
			1u,
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m11(),
		fcppt::make_homogenous_pair(
			1u,
			1u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m12(),
		fcppt::make_homogenous_pair(
			1u,
			2u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m13(),
		fcppt::make_homogenous_pair(
			1u,
			3u
		)
	);


	BOOST_CHECK_EQUAL(
		mat_nc.m10(),
		fcppt::make_homogenous_pair(
			1u,
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m11(),
		fcppt::make_homogenous_pair(
			1u,
			1u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m12(),
		fcppt::make_homogenous_pair(
			1u,
			2u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m13(),
		fcppt::make_homogenous_pair(
			1u,
			3u
		)
	);

	// Row 2
	BOOST_CHECK_EQUAL(
		mat.m20(),
		fcppt::make_homogenous_pair(
			2u,
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m21(),
		fcppt::make_homogenous_pair(
			2u,
			1u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m22(),
		fcppt::make_homogenous_pair(
			2u,
			2u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m23(),
		fcppt::make_homogenous_pair(
			2u,
			3u
		)
	);


	BOOST_CHECK_EQUAL(
		mat_nc.m20(),
		fcppt::make_homogenous_pair(
			2u,
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m21(),
		fcppt::make_homogenous_pair(
			2u,
			1u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m22(),
		fcppt::make_homogenous_pair(
			2u,
			2u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m23(),
		fcppt::make_homogenous_pair(
			2u,
			3u
		)
	);

	// Row 3
	BOOST_CHECK_EQUAL(
		mat.m30(),
		fcppt::make_homogenous_pair(
			3u,
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m31(),
		fcppt::make_homogenous_pair(
			3u,
			1u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m32(),
		fcppt::make_homogenous_pair(
			3u,
			2u
		)
	);

	BOOST_CHECK_EQUAL(
		mat.m33(),
		fcppt::make_homogenous_pair(
			3u,
			3u
		)
	);


	BOOST_CHECK_EQUAL(
		mat_nc.m30(),
		fcppt::make_homogenous_pair(
			3u,
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m31(),
		fcppt::make_homogenous_pair(
			3u,
			1u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m32(),
		fcppt::make_homogenous_pair(
			3u,
			2u
		)
	);

	BOOST_CHECK_EQUAL(
		mat_nc.m33(),
		fcppt::make_homogenous_pair(
			3u,
			3u
		)
	);
}
