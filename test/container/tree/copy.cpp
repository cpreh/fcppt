//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>

BOOST_AUTO_TEST_CASE(
	container_tree_copy
)
{
	typedef fcppt::container::tree::object<
		unsigned
	> ui_tree;

	ui_tree head(
		10
	);

	head.push_back(
		20
	);

	head.push_back(
		30
	);

	ui_tree const head2(
		head
	);

	BOOST_REQUIRE(
		head2.value() == 10
	);

	BOOST_REQUIRE(
		head2.children().size() == 2u
	);

	BOOST_REQUIRE(
		head2.front().value() == 20
	);

	BOOST_REQUIRE(
		head2.back().value() == 30
	);

	BOOST_REQUIRE(
		head2.front().has_parent()
		&&
		&head2.front().parent()
		== &head2
	);

	BOOST_REQUIRE(
		head2.back().has_parent()
		&&
		&head2.back().parent()
		== &head2
	);
}
