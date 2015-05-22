//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	box_comparison
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::math::box::object<
		int,
		2
	> box_type;

	BOOST_CHECK_EQUAL(
		box_type(
			box_type::vector(1,2),
			box_type::dim(3,4)
		),
		box_type(
			box_type::vector(1,2),
			box_type::dim(3,4)
		)
	);

	BOOST_CHECK(
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

	BOOST_CHECK(
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
