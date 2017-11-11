//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/to_root.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_tree_to_root
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::tree::object<
		int
	>
	i_tree;

	i_tree tree(
		1
	);

	fcppt::reference<
		i_tree
	> const child{
		tree.push_back(
			2
		)
	};

	fcppt::reference<
		i_tree
	> const child_2{
		child.get().push_back(
			3
		)
	};

	typedef
	fcppt::container::tree::to_root<
		i_tree const
	>
	traversal_type;

	traversal_type const trav(
		child_2.get()
	);

	traversal_type::iterator it(
		trav.begin()
	);

	BOOST_REQUIRE_EQUAL(
		it->value(),
		3
	);

	++it;

	BOOST_REQUIRE_EQUAL(
		it->value(),
		2
	);

	++it;

	BOOST_REQUIRE_EQUAL(
		it->value(),
		1
	);

	++it;

	BOOST_REQUIRE(
		it
		==
		trav.end()
	);
}
