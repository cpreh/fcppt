//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/depth.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_tree_print
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::container::tree::object<
		std::string
	> string_tree;

	string_tree tree("a");

	tree.push_back(
		std::string("b")
	);

	tree.back().push_back(
		std::string("c")
	);

	tree.push_back(
		std::string("d")
	);

	tree.push_back(
		std::string("e")
	);

	BOOST_CHECK_EQUAL(
		fcppt::container::tree::depth(
			tree),
		3u);
}
