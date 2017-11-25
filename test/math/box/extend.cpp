//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/extend_bounding_box.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_box_extend_bounding_box_vector
)
{
	typedef
	fcppt::math::box::object<
		int,
		2
	>
	box_type;

	box_type b(
		box_type::vector(
			1,
			1
		),
		box_type::dim(
			0,
			0
		)
	);

	fcppt::io::cerr()
		<< FCPPT_TEXT("Original box: ")
		<< b
		<< FCPPT_TEXT('\n');

	b =
		fcppt::math::box::extend_bounding_box(
			b,
			box_type::vector(
				3,
				4
			)
		);

	fcppt::io::cerr()
		<< FCPPT_TEXT("Added (3,4), now: ")
		<< b
		<< FCPPT_TEXT('\n');

	BOOST_CHECK_EQUAL(
		b,
		box_type(
			box_type::vector(
				1,
				1
			),
			box_type::dim(
				2,
				3
			)
		)
	);

	b =
		fcppt::math::box::extend_bounding_box(
			b,
			box_type::vector(
				0,0
			)
		);

	fcppt::io::cerr()
		<< FCPPT_TEXT("Added (0,0), now: ")
		<< b
		<< FCPPT_TEXT('\n');

	// The tests are incremental, so require is...required here
	BOOST_REQUIRE_EQUAL(
		b,
		box_type(
			box_type::vector(
				0,
				0
			),
			box_type::dim(
				3,
				4
			)
		)
	);

	// This point is inside the bounding box -> nothing should change
	b =
		fcppt::math::box::extend_bounding_box(
			b,
			box_type::vector(
				1,
				1
			)
		);

	fcppt::io::cerr()
		<< FCPPT_TEXT("Added (1,1), now: ")
		<< b
		<< FCPPT_TEXT('\n');

	BOOST_REQUIRE_EQUAL(
		b,
		box_type(
			box_type::vector(
				0,
				0
			),
			box_type::dim(
				3,
				4
			)
		)
	);
}

BOOST_AUTO_TEST_CASE(
	math_box_extend_bounding_box_box
)
{
	typedef
	fcppt::math::box::object<
		int,
		2
	>
	box_type;

	box_type const box1(
		box_type::vector(
			1,
			2
		),
		box_type::dim(
			2,
			3
		)
	);

	box_type const box2(
		box_type::vector(
			0,
			1
		),
		box_type::dim(
			2,
			1
		)
	);

	box_type const expected(
		box_type::vector(
			0,
			1
		),
		box_type::dim(
			3,
			4
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::box::extend_bounding_box(
			box1,
			box2
		),
		expected
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::box::extend_bounding_box(
			box2,
			box1
		),
		expected
	);
}
