//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/pi.hpp>
#include <fcppt/math/matrix/componentwise_equal.hpp>
#include <fcppt/math/matrix/identity.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/rotation_axis.hpp>
#include <fcppt/math/matrix/rotation_x.hpp>
#include <fcppt/math/matrix/rotation_y.hpp>
#include <fcppt/math/matrix/rotation_z.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/componentwise_equal.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

float const epsilon{
	0.001f
};

template<
	typename Matrix
>
bool
compare_matrices(
	Matrix const &_m1,
	Matrix const &_m2
)
{
	return
		fcppt::math::matrix::componentwise_equal(
			_m1,
			_m2,
			epsilon
		);
}

}

BOOST_AUTO_TEST_CASE(
	math_matrix_rotation_axis
)
{
	typedef
	fcppt::math::matrix::static_<
		float,
		4,
		4
	>
	matrix_type;

	typedef
	fcppt::math::vector::static_<
		float,
		3
	>
	vector_rotation_type;

	matrix_type const trans(
		fcppt::math::matrix::rotation_axis(
			fcppt::math::pi<
				float
			>(),
			vector_rotation_type(
				1.f,
				0.f,
				0.f
			)
		)
	);

	typedef
	fcppt::math::vector::static_<
		float,
		4
	>
	vector_type;

	vector_type const vec(
		0.f,
		1.f,
		0.f,
		1.f
	);

	BOOST_CHECK(
		fcppt::math::vector::componentwise_equal(
			trans
			*
			vec,
			vector_type(
				0.f,
				-1.f,
				0.f,
				1.f
			),
			epsilon
		)
	);

	BOOST_CHECK((
		::compare_matrices(
			fcppt::math::matrix::rotation_axis(
				0.0f,
				vector_rotation_type(
					0.f,
					0.f,
					0.f
				)
			),
			fcppt::math::matrix::identity<
				matrix_type
			>()
		)
	));

	float const angle{
		fcppt::math::pi<
			float
		>()
		/
		2.f
	};

	BOOST_CHECK((
		::compare_matrices(
			fcppt::math::matrix::rotation_axis(
				angle,
				vector_rotation_type(
					1.0f,
					0.0f,
					0.0f
				)
			),
			fcppt::math::matrix::rotation_x(
				angle
			)
		)
	));

	BOOST_CHECK((
		::compare_matrices(
			fcppt::math::matrix::rotation_axis(
				angle,
				vector_rotation_type(
					0.0f,
					1.0f,
					0.0f
				)
			),
			fcppt::math::matrix::rotation_y(
				angle
			)
		)
	));

	BOOST_CHECK((
		::compare_matrices(
			fcppt::math::matrix::rotation_axis(
				angle,
				vector_rotation_type(
					0.0f,
					0.0f,
					1.0f
				)
			),
			fcppt::math::matrix::rotation_z(
				angle
			)
		)
	));
}
