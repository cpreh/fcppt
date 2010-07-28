#ifndef FCPPT_MATH_MATRIX_ANGLES_FROM_MATRIX_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ANGLES_FROM_MATRIX_HPP_INCLUDED

#include <fcppt/math/matrix/basic.hpp>
#include <fcppt/math/matrix/has_dim.hpp>
#include <fcppt/math/pi.hpp>
#include <boost/mpl/or.hpp>
// DEBUG
//#include <fcppt/io/cout.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
 * This function extracts the euler angles from a rotation matrix.
 * Since those angles aren't unique, it outputs two triples 
 * (whose components are _not_ interchangeable). The last function argument
 * specifies a functor to compare the scalars by. This is because the
 * operations are numerically unstable.
 * 
 * Note that this function is currently not used anywhere and should
 * thus be considered "alpha"
 */
template
<
	typename T,
	typename N,
	typename S,
	typename Functor
>
typename
boost::enable_if
<
	boost::mpl::or_
	<
		has_dim
		<
			basic<T,N,N,S>,
			4,
			4
		>,
		has_dim
		<
			basic<T,N,N,S>,
			3,
			3
		>
	>,
	void
>::type
angles_from_matrix(
	basic<T,N,N,S> const &m,
	T &rx1,
	T &rx2,
	T &ry1,
	T &ry2,
	T &rz1,
	T &rz2,
	Functor const &f)
{
	if (!f(std::abs(m[0][2]),static_cast<T>(1)))
	{
		ry1 = -std::asin(m[0][2]);
		ry2 = fcppt::math::pi<T>() - ry1;
		T const 
			denom1 = std::cos(ry1),
			denom2 = std::cos(ry2);
		rx1 = std::atan2(m[1][2]/denom1,m[2][2]/denom1);
		rx2 = std::atan2(m[1][2]/denom2,m[2][2]/denom2);
		rz1 = std::atan2(m[0][1]/denom1,m[0][0]/denom1);
		rz2 = std::atan2(m[0][1]/denom2,m[0][0]/denom2);
	}
	else
	{
		rz1 = rz2 = static_cast<T>(0);
		if (f(m[0][2],static_cast<T>(-1)))
		{
			ry1 = ry2 = fcppt::math::pi<T>()/static_cast<T>(2);
			rx1 = rx2 = rz1 + std::atan2(m[1][0],m[2][0]);
		}
		else
		{
			ry1 = ry2 = -fcppt::math::pi<T>()/static_cast<T>(2);
			rx1 = rx2 = -rz1 + std::atan2(-m[1][0],-m[2][0]);
		}
		// Testcase for gimbal lock, re-enable if there are problems with it
		/*
		if (f(rz1,static_cast<T>(0)) || f(rz2,static_cast<T>(0)))
		{
			if (f(m[0][2],static_cast<T>(-1)))
				fcppt::io::cout << "SECOND BLOCK, FIRST BRANCH, m[0][2] is " << m[0][2] << ", atan2(" << m[1][0] << ", " << m[2][0] << ")";
			else
				fcppt::io::cout << "SECOND BLOCK, SECOND BRANCH";
			fcppt::io::cout << "\n";
		}
*/

	}
}
}
}
}

#endif
