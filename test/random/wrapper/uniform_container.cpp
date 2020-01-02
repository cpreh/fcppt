//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/algorithm/contains.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/random/generator/minstd_rand.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>
#include <fcppt/random/wrapper/make_uniform_container.hpp>
#include <fcppt/random/wrapper/uniform_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"random::wrapper::uniform_container",
	"[random]"
)
{
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

	CHECK(
		fcppt::algorithm::contains(
			strings,
			dist_inner(
				generator
			)
		)
	);
}
