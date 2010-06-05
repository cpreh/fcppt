//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(math_matrix_view)
{
	typedef int value_type;

	std::size_t const size = 3;

	typedef 
	fcppt::math::matrix::static_<
		value_type,
		size,
		size	
	>::type 
	matrix_type;

	typedef
	fcppt::math::vector::static_<
		value_type,
		size
	>::type
	vector_type;

	matrix_type const t(
		-3, 2, -5,
		-1, 0, -2,
		3, -4, 1
	);

	BOOST_CHECK(
		t[0]
		== vector_type(
			-3,
			2,
			-5
		)
	);
}
