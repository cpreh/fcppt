//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_map
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	std::vector<
		int_unique_ptr
	>
	int_unique_ptr_vector;

	int_unique_ptr_vector const ptrs{
		fcppt::assign::make_container<
			int_unique_ptr_vector
		>(
			fcppt::make_unique_ptr<
				int
			>(
				1
			)
		)(
			fcppt::make_unique_ptr<
				int
			>(
				2
			)
		)
		.move_container()
	};

	int_vector const result(
		fcppt::algorithm::map<
			int_vector
		>(
			ptrs,
			[](
				int_unique_ptr const &_value
			)
			{
				return
					*_value;
			}
		)
	);

	BOOST_REQUIRE(
		result.size()
		==
		ptrs.size()
	);

	BOOST_CHECK(
		result[0] == 1
	);

	BOOST_CHECK(
		result[1] == 2
	);
}
