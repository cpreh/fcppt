//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/null_ptr.hpp>
#include <fcppt/container/data.hpp>
#include <fcppt/container/data_end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_data
)
{
FCPPT_PP_POP_WARNING

	typedef std::vector<
		int
	> int_vector;

	int_vector container;

	BOOST_CHECK(
		fcppt::container::data(
			container
		)
		==
		fcppt::null_ptr()
	);

	BOOST_CHECK(
		fcppt::container::data_end(
			container
		)
		==
		fcppt::null_ptr()
	);

	container.push_back(
		1
	);

	container.push_back(
		2
	);

	BOOST_CHECK(
		std::distance(
			fcppt::container::data(
				container
			),
			fcppt::container::data_end(
				container
			)
		)
		==
		2
	);
}
