//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_tree_move
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::container::tree::object<
		std::string
	> string_tree;

	string_tree tree1(
		"root"
	);

	tree1.push_back(
		"child1"
	);

	string_tree tree2(
		std::move(
			tree1
		)
	);

	BOOST_CHECK(
		tree1.empty()
		&&
		tree1.value()
		==
		""
	);

	BOOST_CHECK(
		tree2.value() == "root"
		&& !tree2.empty()
		&& tree2.front().value() == "child1"
	);

	BOOST_CHECK(
		tree2.front().parent()
		&&
		tree2.front().parent().data()
		==
		&tree2
	);

	string_tree tree3;

	tree3 =
		std::move(
			tree2
		);

	BOOST_CHECK(
		tree2.empty()
		&&
		tree2.value()
		==
		""
	);

	BOOST_CHECK(
		tree3.value() == "root"
		&& !tree3.empty()
		&& tree3.front().value() == "child1"
	);

	BOOST_CHECK(
		tree3.front().parent()
		&&
		tree3.front().parent().data()
		==
		&tree3
	);
}
