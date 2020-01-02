//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/depth.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tree::depth",
	"[container],[tree]"
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

	CHECK(
		fcppt::container::tree::depth(
			leaf.get()
		)
		==
		1u
	);

	CHECK(
		fcppt::container::tree::depth(
			child_1.get()
		)
		==
		2u
	);

	CHECK(
		fcppt::container::tree::depth(
			tree
		)
		==
		3u
	);
}
