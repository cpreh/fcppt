//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/adjugate.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(adjugate)
{
	typedef
	fcppt::math::matrix::static_<
		int,
		3,
		3
	>::type
	matrix_type;

	matrix_type const t(
		-3, 2, -5,
		-1, 0, -2,
		3, -4, 1);

	BOOST_CHECK(
		(
		fcppt::math::matrix::adjugate(
			t) ==
		matrix_type(
			-8,18,-4,
			-5,12,-1,
			4,-6,2)));
}
