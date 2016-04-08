//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_tree_swap
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::tree::object<
		int
	>
	i_tree;

	i_tree tree1(
		10
	);

	tree1.push_back(
		20
	);

	i_tree tree2(
		30
	);

	swap(
		tree1,
		tree2
	);

	BOOST_CHECK_EQUAL(
		tree1.value(),
		30
	);

	BOOST_CHECK_EQUAL(
		tree2.value(),
		10
	);

	BOOST_REQUIRE(
		!tree2.empty()
	);

	BOOST_CHECK_EQUAL(
		tree2.front().value(),
		20
	);
}
