//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/read_from.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_buffer_read_from
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::buffer::object<
		int
	>
	buffer_type;

	buffer_type const result{
		fcppt::container::buffer::read_from<
			buffer_type
		>(
			10u,
			[](
				buffer_type::pointer const _data,
				buffer_type::size_type
			)
			{
				_data[
					0
				] = 10;

				_data[
					1
				] = 20;

				return
					2u;
			}
		)
	};

	BOOST_CHECK_EQUAL(
		result.read_size(),
		2u
	);

	BOOST_CHECK_EQUAL(
		result.write_size(),
		8u
	);

	BOOST_CHECK_EQUAL(
		result[0],
		10
	);

	BOOST_CHECK_EQUAL(
		result[1],
		20
	);
}
