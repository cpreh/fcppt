//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/shrink.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_box_shrink
)
{
	typedef
	fcppt::math::box::object<
		int,
		2
	>
	signed_box_type;

	signed_box_type const b(
		signed_box_type::vector(
			10,
			12
		),
		signed_box_type::dim(
			24,
			26
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::box::shrink(
			b,
			signed_box_type::vector(
				2,
				5
			)
		),
		signed_box_type(
			signed_box_type::vector(
				12,
				17
			),
			signed_box_type::dim(
				20,
				16
			)
		)
	);
}
