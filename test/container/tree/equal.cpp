//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/comparison.hpp>
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
	container_tree_equal
)
{
FCPPT_PP_POP_WARNING

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

	BOOST_CHECK(
		tree1 == tree2
	);

	tree2.push_back(
		200
	);

	BOOST_CHECK(
		tree1 != tree2
	);
}
