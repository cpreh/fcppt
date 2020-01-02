//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/strong_typedef_std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

}

TEST_CASE(
	"strong_typedef_hash",
	"[strongtypedef]"
)
{
	typedef
	std::unordered_set<
		strong_int
	>
	hash_set;

	hash_set const elements{
		strong_int(1),
		strong_int(2)
	};

	CHECK(
		elements.count(
			strong_int(1)
		)
		==
		1u
	);

	CHECK(
		elements.count(
			strong_int(2)
		)
		==
		1u
	);

	CHECK(
		elements.count(
			strong_int(3)
		)
		==
		0u
	);
}
