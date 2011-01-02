//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/object.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <ostream>
#include <cstdlib>

//[tree_traversal
int main()
try
{
	typedef fcppt::container::tree::object<
		fcppt::string
	> string_tree;

	string_tree tree(
		FCPPT_TEXT("hello")
	);

	tree.push_back(
		FCPPT_TEXT("foo")
	);

	tree.push_back(
		FCPPT_TEXT("bar")
	);

	tree.push_back(
		FCPPT_TEXT("baz")
	);

	tree.front().push_back(
		FCPPT_TEXT("qux")
	);

	typedef
	fcppt::container::tree::pre_order<string_tree const> 
	traversal_type;

	traversal_type const trav(
		tree
	);

	for(
		traversal_type::iterator it = trav.begin();
		it != trav.end();
		++it
	)
		fcppt::io::cout
			<< (*it).value()
			<< std::endl;
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');
	
	return EXIT_FAILURE;
}
//]
