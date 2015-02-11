//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/float_to_int_fun.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/structure_cast.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_box_structure_cast
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::math::box::object<
		float,
		2
	> box_f2;

	typedef fcppt::math::box::object<
		int,
		2
	> box_i2;

	box_f2 const box1(
		box_f2::vector(
			1.5f,
			2.5f
		),
		box_f2::dim(
			3.5f,
			4.5f
		)
	);

	BOOST_REQUIRE((
		fcppt::math::box::structure_cast<
			box_i2,
			fcppt::cast::float_to_int_fun
		>(
			box1
		)
		==
		box_i2(
			box_i2::vector(
				1,
				2
			),
			box_i2::dim(
				3,
				4
			)
		)
	));
}
