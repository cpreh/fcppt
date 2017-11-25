//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/depth.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_tree_depth
)
{
	typedef
	fcppt::container::tree::object<
		std::string
	>
	string_tree;

	string_tree tree("a");

	fcppt::reference<
		string_tree
	> const child_1{
		tree.push_back(
			std::string("b")
		)
	};

	child_1.get().push_back(
		std::string("c")
	);

	fcppt::reference<
		string_tree
	> const leaf{
		tree.push_back(
			std::string("d")
		)
	};

	tree.push_back(
		std::string("e")
	);

	BOOST_CHECK_EQUAL(
		fcppt::container::tree::depth(
			leaf.get()
		),
		1u
	);

	BOOST_CHECK_EQUAL(
		fcppt::container::tree::depth(
			child_1.get()
		),
		2u
	);

	BOOST_CHECK_EQUAL(
		fcppt::container::tree::depth(
			tree
		),
		3u
	);
}
