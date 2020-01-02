//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/copy_value.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::copy_value",
	"[optional]"
)
{
	typedef
	fcppt::optional::reference<
		std::string const
	>
	optional_string_ref;

	std::string const test(
		"test1"
	);

	CHECK(
		fcppt::optional::copy_value(
			optional_string_ref{
				fcppt::make_cref(
					test
				)
			}
		)
		==
		fcppt::optional::object<
			std::string
		>(
			std::string(
				"test1"
			)
		)
	);
}
