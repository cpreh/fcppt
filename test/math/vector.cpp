//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/diff.hpp>
#include <fcppt/math/pi.hpp>
#include <fcppt/math/vector/angle_between.hpp>
#include <fcppt/math/vector/angle_between_cast.hpp>
#include <fcppt/math/vector/componentwise_equal.hpp>
#include <fcppt/math/vector/hypersphere_to_cartesian.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/signed_angle_between.hpp>
#include <fcppt/math/vector/signed_angle_between_cast.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cmath>
#include <iostream>
#include <limits>
#include <fcppt/config/external_end.hpp>


namespace
{
typedef
float
real;

real const
epsilon(
	std::numeric_limits<
		real
	>::epsilon()
);

typedef
fcppt::math::vector::static_<
	unsigned,
	2
>
uivector2;

typedef
fcppt::math::vector::static_<real,1>
fvector1;

typedef
fcppt::math::vector::static_<real,2>
fvector2;

typedef
fcppt::math::vector::static_<real,3>
fvector3;

template<typename T>
bool
compare(
	T const &t1,
	T const &t2)
{
	return fcppt::math::diff(t1, t2) < epsilon;
}
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(vector_angle_between)
{
FCPPT_PP_POP_WARNING

	fvector2 const
		vec1(1.f, 0.f),
		vec2(0.f, 1.f);

	BOOST_CHECK(
		::compare(
			fcppt::math::vector::angle_between(
				vec1,
				vec2
			),
			fcppt::math::pi<real>() / 2.f
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(vector_angle_between_cast)
{
FCPPT_PP_POP_WARNING

	uivector2 const
		vec1(1u, 0u),
		vec2(0u, 1u);

	BOOST_CHECK(
		::compare(
			fcppt::math::vector::angle_between_cast<
				real
			>(
				vec1,
				vec2
			),
			fcppt::math::pi<real>() / 2.f
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(vector_signed_angle_between)
{
FCPPT_PP_POP_WARNING

	fvector2 const
		vec1(2.f, 1.f),
		vec2(2.f, 2.f);

	BOOST_CHECK(
		::compare(
			fcppt::math::vector::signed_angle_between(
				vec1,
				vec2
			),
			fcppt::math::pi<real>() / 2.f
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(vector_signed_angle_between_cast)
{
FCPPT_PP_POP_WARNING

	uivector2 const
		vec1(2u, 1u),
		vec2(2u, 2u);

	BOOST_CHECK(
		::compare(
			fcppt::math::vector::signed_angle_between_cast<
				real
			>(
				vec1,
				vec2
			),
			fcppt::math::pi<real>() / 2.f
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(vector_hypersphere_to_cartesian)
{
FCPPT_PP_POP_WARNING

	real const
		phi1 =
			fcppt::literal<real>(1.5),
		phi2 =
			fcppt::literal<real>(0.5);

	fvector2 const result2 =
		fcppt::math::vector::hypersphere_to_cartesian(
			fvector1(
				phi1));

	fvector3 const result3 =
		fcppt::math::vector::hypersphere_to_cartesian(
			fvector2(
				phi1,
				phi2));

	std::cout
		<< "Testing the result of 2D hypersphere_to_cartesian.\n"
		<< "The result should be:\n"
		<<
			fvector2(
				std::cos(
					phi1),
				std::sin(
					phi1))
		<< "\n and it is:\n"
		<< result2
		<< "\n";

	BOOST_CHECK(
		fcppt::math::vector::componentwise_equal(
			result2,
			fvector2(
				std::cos(
					phi1),
				std::sin(
					phi1)),
			epsilon));

	std::cout
		<< "Testing the result of 3D hypersphere_to_cartesian.\n"
		<< "The result should be:\n"
		<<
			fvector3(
				std::cos(
					phi1),
				std::sin(
					phi1) *
				std::cos(
					phi2),
				std::sin(
					phi1) *
				std::sin(
					phi2))
		<< "\n and it is:\n"
		<< result3
		<< "\n";

	BOOST_CHECK(
		fcppt::math::vector::componentwise_equal(
			result3,
			fvector3(
				std::cos(
					phi1),
				std::sin(
					phi1) *
				std::cos(
					phi2),
				std::sin(
					phi1) *
				std::sin(
					phi2)),
			epsilon));
}
