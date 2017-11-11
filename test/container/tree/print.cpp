//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/print.hpp>
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

	typedef
	fcppt::container::tree::object<
		std::string
	>
	string_tree;

	string_tree tree("a");

	fcppt::reference<
		string_tree
	> const child{
		tree.push_back(
			std::string("b")
		)
	};

	child.get().push_back(
		std::string("c")
	);

	tree.push_back(
		std::string("d")
	);

	tree.push_back(
		std::string("e")
	);

	std::ostringstream oss;

	fcppt::container::tree::print(
		oss,
		tree
	);

	std::cout
		<< oss.str()
		<< '\n';

	BOOST_CHECK_EQUAL(
		oss.str(),
		"a\n"
			"\tb\n"
				"\t\tc\n"
			"\td\n"
			"\te\n"
	);
}
