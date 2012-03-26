//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/stretch_relative.hpp>
#include <fcppt/math/box/stretch_absolute.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(box_stretch)
{
	typedef fcppt::math::box::object<
		int,
		3
	> box_type;

	box_type b(
		box_type::vector(10,12,14),
		box_type::dim(24,26,4));

	BOOST_CHECK(
		fcppt::math::box::stretch_absolute(
			b,
			box_type::vector(
				2,
				2,
				2)
		)
		==
		box_type(
			box_type::vector(
				8,
				10,
				12
			),
			box_type::dim(
				28,
				30,
				8
			)
		)
	);

	BOOST_CHECK(
		fcppt::math::box::stretch_relative(
			b,
			box_type::vector(
				2,
				2,
				2)
		)
		==
		box_type(
			box_type::vector(
				-2,
				-1,
				12
			),
			box_type::dim(
				48,
				52,
				8
			)
		)
	);
}
