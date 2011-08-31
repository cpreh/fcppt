//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/tree.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>

BOOST_AUTO_TEST_CASE(
	container_tree_equal
)
{
	typedef fcppt::container::tree::object<
		unsigned
	> ui_tree;

	ui_tree tree1(
		42
	);

	tree1.push_back(
		100
	);

	ui_tree tree2(
		42
	);

	tree2.push_back(
		100
	);

	BOOST_REQUIRE(
		tree1 == tree2
	);

	tree2.push_back(
		200
	);

	BOOST_REQUIRE(
		tree1 != tree2
	);
}
