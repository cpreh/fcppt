//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/level.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tree::level",
	"[container],[tree]"
)
{
	typedef
	fcppt::container::tree::object<
		int
	>
	int_tree;

	int_tree tree(
		42
	);

	CHECK(
		fcppt::container::tree::level(
			tree
		)
		==
		0u
	);

	fcppt::reference<
		int_tree
	> const back{
		tree.push_back(
			13
		)
	};

	CHECK(
		fcppt::container::tree::level(
			tree
		)
		==
		0u
	);

	CHECK(
		fcppt::container::tree::level(
			back.get()
		)
		==
		1u
	);
}
