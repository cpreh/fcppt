//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_tree_pre_order
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::container::tree::object<
		unsigned
	> ui_tree;

	ui_tree tree(
		1
	);

	tree.push_back(
		2
	);

	tree.front().push_back(
		3
	);

	tree.front().push_back(
		4
	);

	tree.push_back(
		5
	);

	tree.push_back(
		6
	);

	typedef fcppt::container::tree::pre_order<
		ui_tree const
	> traversal_type;

	traversal_type const trav(
		tree
	);

	traversal_type::iterator it(
		trav.begin()
	);

	BOOST_REQUIRE(
		it->value() == 1
	);

	++it;

	BOOST_REQUIRE(
		it->value() == 2
	);

	++it;

	BOOST_REQUIRE(
		it->value() == 3
	);

	++it;

	BOOST_REQUIRE(
		it->value() == 4
	);

	++it;

	BOOST_REQUIRE(
		it->value() == 5
	);

	++it;

	BOOST_REQUIRE(
		it->value() == 6
	);

	++it;

	BOOST_REQUIRE(
		it == trav.end()
	);
}

template class fcppt::container::tree::object<
	unsigned
>;
