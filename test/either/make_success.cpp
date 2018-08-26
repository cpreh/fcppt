//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/make_success.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/success_opt.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::make_success",
	"[either]"
)
{
	fcppt::either::object<
		std::string,
		int
	> const result{
		fcppt::either::make_success<
			std::string
		>(
			42
		)
	};

	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	CHECK(
		fcppt::either::success_opt(
			result
		)
		==
		optional_int(
			42
		)
	);
}
