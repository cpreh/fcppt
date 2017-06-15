//          Copyright Carl Philipp Reh 2009 - 2017.
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


int
main()
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
	// Then use it like a forward-iterable container!
	// This outputs:
	//
	// hello, foo, qux, bar, baz
	for(
		string_tree const &item
		:
		fcppt::container::tree::pre_order<
			string_tree const
		>(
			tree
		)
	)
		fcppt::io::cout()
			<< item.value()
			<< std::endl;
	//! [main]
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');

	return
		EXIT_FAILURE;
}
