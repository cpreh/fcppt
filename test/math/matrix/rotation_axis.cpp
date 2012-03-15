//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/pi.hpp>
#include <fcppt/math/range_compare.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/rotation_axis.hpp>
#include <fcppt/math/matrix/rotation_x.hpp>
#include <fcppt/math/matrix/rotation_y.hpp>
#include <fcppt/math/matrix/rotation_z.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{
float const epsilon = 0.001f;

template<typename Matrix>
bool
compare_matrices(
	Matrix const &m1,
	Matrix const &m2)
{
	return
		fcppt::math::range_compare(
			boost::make_iterator_range(
				m1.data(),
				m1.data() + m1.size()),
			boost::make_iterator_range(
				m2.data(),
				m2.data() + m2.size()),
			epsilon);
}
}

BOOST_AUTO_TEST_CASE(math_matrix_rotation_axis)
{
	typedef fcppt::math::matrix::static_<
		float,
		4,
		4
	>::type matrix_type;

	typedef fcppt::math::vector::static_<
		float,
		3
	>::type vector_rotation_type;

	matrix_type const trans_(
		fcppt::math::matrix::rotation_axis(
			fcppt::math::pi<float>(),
			vector_rotation_type(
				1.f,
				0.f,
				0.f
			)
		)
	);

	typedef fcppt::math::vector::static_<
		float,
		4
	>::type vector_type;

	vector_type const vec_(
		0.f,
		1.f,
		0.f,
		1.f
	);

	BOOST_REQUIRE(
		fcppt::math::range_compare(
			trans_ * vec_,
			vector_type(
				0.f,
				-1.f,
				0.f,
				1.f
			),
			epsilon)
	);

	BOOST_CHECK((
		::compare_matrices(
			fcppt::math::matrix::rotation_axis(
				0.0f,
				vector_rotation_type(
					0.f,
					0.f,
					0.f)),
			matrix_type::identity())));

	float const angle =
		fcppt::math::pi<float>()/2.0f;

	BOOST_CHECK((
		::compare_matrices(
			fcppt::math::matrix::rotation_axis(
				angle,
				vector_rotation_type(
					1.0f,
					0.0f,
					0.0f)),
			fcppt::math::matrix::rotation_x(
				angle))));

	BOOST_CHECK((
		::compare_matrices(
			fcppt::math::matrix::rotation_axis(
				angle,
				vector_rotation_type(
					0.0f,
					1.0f,
					0.0f)),
			fcppt::math::matrix::rotation_y(
				angle))));

	BOOST_CHECK((
		::compare_matrices(
			fcppt::math::matrix::rotation_axis(
				angle,
				vector_rotation_type(
					0.0f,
					0.0f,
					1.0f)),
			fcppt::math::matrix::rotation_z(
				angle))));
}
