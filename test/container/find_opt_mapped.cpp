//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <map>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::find_opt_mapped",
	"[container]"
)
{
	typedef
	std::map<
		int,
		std::string
	>
	int_string_map;

	int_string_map const values{
		std::make_pair(
			42,
			std::string(
				"test"
			)
		),
		std::make_pair(
			100,
			std::string(
				"test2"
			)
		)
	};

	typedef
	fcppt::optional::object<
		fcppt::reference<
			std::string const
		>
	>
	optional_string;

	CHECK(
		optional_string(
			fcppt::container::find_opt_mapped(
				values,
				42
			)
		)
		==
		optional_string(
			fcppt::make_cref(
				values.at(
					42
				)
			)
		)
	);

	CHECK_FALSE(
		fcppt::container::find_opt_mapped(
			values,
			50
		).has_value()
	);
}
