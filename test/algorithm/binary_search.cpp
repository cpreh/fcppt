//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/binary_search.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_binary_search
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec{
		2,
		5,
		7
	};

	{
		auto const result(
			fcppt::algorithm::binary_search(
				vec,
				3
			)
		);

		BOOST_CHECK(
			!result.has_value()
		);
	}

	{
		auto const result(
			fcppt::algorithm::binary_search(
				vec,
				5
			)
		);

		BOOST_REQUIRE(
			result.has_value()
		);

		BOOST_CHECK(
			result.get_unsafe()
			==
			std::next(
				vec.begin(),
				1
			)
		);
	}
}
