//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/split_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm_split_string"
	"[algorithm]"
)
{
	CHECK(
		fcppt::algorithm::split_string(
			std::string{""},
			'x'
		)
		==
		std::vector<
			std::string
		>{
			std::string{}
		}
	);

	CHECK(
		fcppt::algorithm::split_string(
			std::string{"x"},
			'x'
		)
		==
		std::vector<
			std::string
		>{
			std::string{},
			std::string{}
		}
	);

	CHECK(
		fcppt::algorithm::split_string(
			std::string{"ax"},
			'x'
		)
		==
		std::vector<
			std::string
		>{
			std::string{
				"a"
			},
			std::string{}
		}
	);

	CHECK(
		fcppt::algorithm::split_string(
			std::string{"xa"},
			'x'
		)
		==
		std::vector<
			std::string
		>{
			std::string{},
			std::string{
				"a"
			}
		}
	);

	CHECK(
		fcppt::algorithm::split_string(
			std::string{"aaxbb"},
			'x'
		)
		==
		std::vector<
			std::string
		>{
			std::string{
				"aa"
			},
			std::string{
				"bb"
			}
		}
	);

	CHECK(
		fcppt::algorithm::split_string(
			std::string{"aaxbbxc"},
			'x'
		)
		==
		std::vector<
			std::string
		>{
			std::string{
				"aa"
			},
			std::string{
				"bb"
			},
			std::string{
				"c"
			}
		}
	);
}
