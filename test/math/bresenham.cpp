//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/bresenham.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_bresenham
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	int2_vector;

	typedef
	std::vector<
		int2_vector
	>
	int2_vector_sequence;

	int2_vector_sequence result;

	fcppt::math::bresenham(
		int2_vector(
			0,
			0
		),
		int2_vector(
			10,
			4
		),
		[
			&result
		](
			int2_vector const _vec
		)
		{
			result.push_back(
				_vec
			);

			return true;
		}
	);

	BOOST_REQUIRE(
		result.size()
		==
		11u
	);

	BOOST_CHECK(
		result[0]
		==
		int2_vector(
			0,
			0
		)
	);

	BOOST_CHECK(
		result[1]
		==
		int2_vector(
			1,
			0
		)
	);

	BOOST_CHECK(
		result[2]
		==
		int2_vector(
			2,
			1
		)
	);

	BOOST_CHECK(
		result[3]
		==
		int2_vector(
			3,
			1
		)
	);

	BOOST_CHECK(
		result[4]
		==
		int2_vector(
			4,
			2
		)
	);

	BOOST_CHECK(
		result[5]
		==
		int2_vector(
			5,
			2
		)
	);

	BOOST_CHECK(
		result[6]
		==
		int2_vector(
			6,
			2
		)
	);

	BOOST_CHECK(
		result[7]
		==
		int2_vector(
			7,
			3
		)
	);

	BOOST_CHECK(
		result[8]
		==
		int2_vector(
			8,
			3
		)
	);

	BOOST_CHECK(
		result[9]
		==
		int2_vector(
			9,
			4
		)
	);

	BOOST_CHECK(
		result[10]
		==
		int2_vector(
			10,
			4
		)
	);
}
