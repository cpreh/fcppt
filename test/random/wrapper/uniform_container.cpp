//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/contains.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/random/generator/minstd_rand.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>
#include <fcppt/random/wrapper/make_uniform_container.hpp>
#include <fcppt/random/wrapper/uniform_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	random_wrapper_uniform_container
)
{

FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		std::string
	>
	string_vector;

	string_vector const strings{
		std::string("test1"),
		std::string("test2")
	};

	auto dist(
		fcppt::random::wrapper::make_uniform_container(
			strings
		)
	);

	auto &dist_inner(
		FCPPT_ASSERT_OPTIONAL_ERROR(
			dist
		)
	);

	fcppt::random::generator::minstd_rand generator(
		fcppt::random::generator::seed_from_chrono<
			fcppt::random::generator::minstd_rand::seed
		>()
	);

	BOOST_CHECK(
		fcppt::algorithm::contains(
			strings,
			dist_inner(
				generator
			)
		)
	);
}
