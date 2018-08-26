//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

struct throw_cctor
{
	throw_cctor()
	{
	}

	throw_cctor(
		throw_cctor const &
	)
	{
		throw
			fcppt::exception(
				FCPPT_TEXT("Throwing cctor")
			);
	}

	throw_cctor(
		throw_cctor &&
	)
	{
		throw
			fcppt::exception(
				FCPPT_TEXT("Throwing move cctor")
			);
	}

	throw_cctor &
	operator=(
		throw_cctor const &
	) = default;

	throw_cctor &
	operator=(
		throw_cctor &&
	) = default;
};

}

TEST_CASE(
	"variant exception",
	"[variant]"
)
{
	typedef
	fcppt::variant::variadic<
		std::string,
		throw_cctor
	>
	variant;

	variant test(
		std::string("test")
	);

	CHECK_FALSE(
		test.is_invalid()
	);

	throw_cctor const test_cctor{};

	CHECK_THROWS_AS(
		test =
			test_cctor,
		fcppt::exception
	);

	CHECK(
		test.is_invalid()
	);

	CHECK_THROWS_AS(
		test =
			throw_cctor(),
		fcppt::exception
	);

	CHECK(
		test.is_invalid()
	);
}
