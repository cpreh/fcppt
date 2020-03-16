//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/make_literal_strong_typedef.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"literal fundamental",
	"[literal]"
)
{
	CHECK(
		fcppt::literal<
			unsigned
		>(
			2
		)
		==
		2U
	);
}

TEST_CASE(
	"literal strong_typedef",
	"[literal]"
)
{
	FCPPT_MAKE_STRONG_TYPEDEF(
		int,
		my_type
	);

	CHECK(
		fcppt::literal<
			my_type
		>(
			1
		).get()
		==
		1
	);
}
