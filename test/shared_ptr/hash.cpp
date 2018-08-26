//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/shared_ptr_output.hpp>
#include <fcppt/shared_ptr_std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"shared_ptr hash",
	"[smartptr]"
)
{
	typedef
	fcppt::shared_ptr<
		int
	>
	int_shared_ptr;

	typedef
	std::unordered_set<
		int_shared_ptr
	>
	int_shared_ptr_set;

	int_shared_ptr const x(
		fcppt::make_shared_ptr<
			int
		>(
			42
		)
	);

	int_shared_ptr_set const set{
		x
	};

	SECTION(
		"found"
	)
	{
		int_shared_ptr_set::const_iterator const it(
			set.find(
				x
			)
		);

		REQUIRE(
			it
			!=
			set.end()
		);

		CHECK(
			*it
			==
			x
		);
	}

	SECTION(
		"not found"
	)
	{
		int_shared_ptr const y(
			fcppt::make_shared_ptr<
				int
			>(
				42
			)
		);

		CHECK(
			set.count(
				y
			)
			==
			0u
		);
	}
}
