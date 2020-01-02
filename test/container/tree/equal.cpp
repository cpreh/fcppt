//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/comparison.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tree equal",
	"[container],[tree]"
)
{
	typedef
	fcppt::container::tree::object<
		unsigned
	>
	ui_tree;

	ui_tree tree1{
		42
	};

	tree1.push_back(
		100
	);

	ui_tree tree2{
		42
	};

	tree2.push_back(
		100
	);

	CHECK(
		tree1
		==
		tree2
	);

	tree2.push_back(
		200
	);

	CHECK(
		tree1
		!=
		tree2
	);
}
