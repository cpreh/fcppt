//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/resize_write_area.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_buffer_resize_write_area
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::buffer::object<
		int
	>
	container_type;

	container_type container{
		2u
	};

	container.write_data()[0] = 10;

	container.written(
		1u
	);

	BOOST_CHECK_EQUAL(
		container.read_size(),
		1u
	);

	BOOST_CHECK_EQUAL(
		container.write_size(),
		1u
	);

	container =
		fcppt::container::buffer::resize_write_area(
			container,
			3u
		);

	BOOST_CHECK_EQUAL(
		container.read_size(),
		1u
	);

	BOOST_CHECK_EQUAL(
		container.write_size(),
		5u
	);

	BOOST_CHECK_EQUAL(
		container[0],
		10
	);
}
