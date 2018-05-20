//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::reference<
	int
>
int_ref;

typedef
fcppt::reference<
	int const
>
const_int_ref;

}

TEST_CASE(
	"reference",
	"[ref]"
)
{
	int x(
		42
	);

	int_ref ref(
		x
	);

	CHECK(
		&ref.get()
		==
		&x
	);

	const_int_ref const cref(
		x
	);

	CHECK(
		&cref.get()
		==
		&x
	);

	CHECK(
		&fcppt::make_ref(
			x
		).get()
		==
		&x
	);

	CHECK(
		&fcppt::make_cref(
			x
		).get()
		==
		&x
	);

	int_ref other_ref(
		ref
	);

	CHECK(
		&other_ref.get()
		==
		&ref.get()
	);

	ref =
		other_ref;

	CHECK(
		&other_ref.get()
		==
		&ref.get()
	);
}

TEST_CASE(
	"reference hash",
	"[ref]"
)
{
	typedef
	std::unordered_set<
		int_ref
	>
	int_ref_set;

	SECTION(
		"set"
	)
	{
		int x(
			42
		);

		int_ref_set const set{
			int_ref(
				x
			)
		};

		int_ref_set::const_iterator const it(
			set.find(
				int_ref(
					x
				)
			)
		);

		REQUIRE(
			it
			!=
			set.end()
		);

		CHECK(
			&it->get()
			==
			&x
		);
	}

	SECTION(
		"const set"
	)
	{
		typedef
		std::unordered_set<
			const_int_ref
		>
		const_int_ref_set;

		int const y(
			42
		);

		const_int_ref_set const const_set{
			const_int_ref(
				y
			)
		};

		const_int_ref_set::const_iterator const it(
			const_set.find(
				const_int_ref(
					y
				)
			)
		);

		REQUIRE(
			it
			!=
			const_set.end()
		);

		CHECK(
			&it->get()
			==
			&y
		);
	}
}
