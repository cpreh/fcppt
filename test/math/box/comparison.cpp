//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::box comparison",
	"[math],[box]"
)
{
	typedef
	fcppt::math::box::object<
		int,
		2
	>
	box_type;

	CHECK(
		box_type(
			box_type::vector(1,2),
			box_type::dim(3,4)
		)
		==
		box_type(
			box_type::vector(1,2),
			box_type::dim(3,4)
		)
	);

	CHECK(
		box_type(
			box_type::vector(1,2),
			box_type::dim(3,4)
		)
		!=
		box_type(
			box_type::vector(5,2),
			box_type::dim(3,4)
		)
	);

	CHECK(
		box_type(
			box_type::vector(1,2),
			box_type::dim(3,4)
		)
		<
		box_type(
			box_type::vector(5,2),
			box_type::dim(3,4)
		)
	);
}
