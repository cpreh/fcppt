//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/angles_from_matrix.hpp>
#include <fcppt/math/matrix/rotation_x.hpp>
#include <fcppt/math/matrix/rotation_y.hpp>
#include <fcppt/math/matrix/rotation_z.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/almost_zero.hpp>
#include <fcppt/math/twopi.hpp>
#include <fcppt/math/pi.hpp>
#include <fcppt/random/uniform.hpp>
#include <fcppt/random/make_inclusive_range.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <boost/test/unit_test.hpp>
#include <cmath>

namespace
{
// NOTE: The functions gets a compare functor. The one below isn't as
// strict as fcppt::math::compare as it doesn't use the machine
// epsilon
template<typename T>
bool
mycompare(
	T const &a,
	T const &b)
{
	return 
		std::abs(a-b) < static_cast<T>(0.0001);
}
}

BOOST_AUTO_TEST_CASE(angles_from_matrix)
{
	typedef
	float
	real;

	typedef 
	fcppt::math::matrix::static_<
		real,
		4,
		4
	>::type 
	matrix_type;

	unsigned const iterations = 100000;

	fcppt::random::uniform<real> rng(
		fcppt::random::make_inclusive_range(
			static_cast<real>(0),
			fcppt::math::pi<real>()));	

	for (unsigned i = 0; i < iterations; ++i)
	{
		real const 
			rx = rng(),
			ry = rng(),
			rz = rng();	

		real rx1,rx2,ry1,ry2,rz1,rz2;

		matrix_type const m =
			fcppt::math::matrix::rotation_x(
				rx) * 
			fcppt::math::matrix::rotation_y(
				ry) * 
			fcppt::math::matrix::rotation_z(
				rz);

		fcppt::math::matrix::angles_from_matrix(
			m,
			rx1,rx2,ry1,ry2,rz1,rz2,
			&mycompare<real>);

		bool const check = 
			// ry == pi/2 is a special case in which rz can be arbitrary (gimbal lock)
			mycompare(std::abs(m[0][2]),static_cast<real>(1))
			?
				true
			:
				((mycompare(rx1,rx) && 
				mycompare(ry1,ry) && 
				mycompare(rz1,rz)) 
				||
				(mycompare(rx2,rx) && 
				mycompare(ry2,ry) && 
				mycompare(rz2,rz)));

		if (!check)
			fcppt::io::cout 
				<< FCPPT_TEXT("Input:  ")
				<< FCPPT_TEXT("(") << rx << FCPPT_TEXT(", ") << ry << FCPPT_TEXT(", ") << rz  << FCPPT_TEXT(")")
				<< FCPPT_TEXT("\n")
				<< FCPPT_TEXT("Output: ")
				<< FCPPT_TEXT("(") << rx1 << FCPPT_TEXT(", ") << ry1 << FCPPT_TEXT(", ") << rz1 << FCPPT_TEXT(")")
				<< FCPPT_TEXT(" and ")
				<< FCPPT_TEXT("(") << rx2 << FCPPT_TEXT(", ") << ry2 << FCPPT_TEXT(", ") << rz2 << FCPPT_TEXT(")")
				<< std::endl;

		BOOST_CHECK(
			check);
	}
}
