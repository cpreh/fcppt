//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/to_raw_vector.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_buffer_to_raw_vector
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::buffer::object<
		int
	>
	buffer_type;

	buffer_type buffer{
		2u
	};

	buffer.write_data()[
		0
	]
		= 10;

	buffer.written(
		1u
	);

	typedef
	fcppt::container::raw_vector::object<
		int
	>
	raw_vector_type;

	raw_vector_type raw_vector{
		fcppt::container::buffer::to_raw_vector(
			std::move(
				buffer
			)
		)
	};

	BOOST_REQUIRE_EQUAL(
		buffer.read_size(),
		0u
	);

	BOOST_REQUIRE_EQUAL(
		buffer.write_size(),
		0u
	);

	BOOST_REQUIRE_EQUAL(
		raw_vector.size(),
		1u
	);

	BOOST_REQUIRE_EQUAL(
		raw_vector.capacity(),
		2u
	);

	BOOST_CHECK_EQUAL(
		raw_vector[
			0
		],
		10
	);
}
