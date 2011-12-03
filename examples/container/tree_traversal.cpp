//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/tree/object.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int main()
try
{
	//! [main]
	typedef fcppt::container::tree::object<
		fcppt::string
	> string_tree;

	// Create a tree, insert 5 elements below the root
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

	// Create a traversal and "attach" it to the tree in the ctor
	typedef
	fcppt::container::tree::pre_order<string_tree const>
	traversal_type;

	traversal_type const trav(
		tree
	);

	// Then use it like a forward-iterable container!
	// This outputs:
	//
	// hello, foo, qux, bar, baz
	for(
		traversal_type::iterator it = trav.begin();
		it != trav.end();
		++it
	)
		fcppt::io::cout()
			<< (*it).value()
			<< std::endl;
	//! [main]
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr()
		<< e.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
