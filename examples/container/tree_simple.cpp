//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[tree_simple
#include <fcppt/container/tree/object.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/move.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>

int main()
try
{
	typedef
	fcppt::container::tree::object<
		fcppt::string
	>
	string_tree;

	string_tree tree(
		FCPPT_TEXT("hello")
	);

	// Immediately change the value
	tree.value(
		tree.value()+FCPPT_TEXT(" world")
	);

	// The tree is empty since it has no children
	fcppt::io::cout()
		<< FCPPT_TEXT("Is the tree empty? ")
		<< tree.empty()
		<< FCPPT_TEXT('\n');

	{
		// Adding two items via an unique_ptr and passing ownership
		string_tree::unique_ptr child1(
			fcppt::make_unique_ptr<
				string_tree
			>(
				FCPPT_TEXT("blubb")
			)
		);

		tree.push_back(
			fcppt::move(
				child1
			)
		);

		string_tree::unique_ptr child2(
			fcppt::make_unique_ptr<
				string_tree
			>(
				FCPPT_TEXT("blah")
			)
		);

		tree.push_back(
			fcppt::move(
				child2
			)
		);
	}

	// adding "by value"
	tree.push_back(
		FCPPT_TEXT("foobar")
	);

	// Now the tree isn't empty anymore
	fcppt::io::cout()
		<< FCPPT_TEXT("Is the tree empty? ")
		<< tree.empty()
		<< FCPPT_TEXT('\n');

	// Outputs 3
	fcppt::io::cout()
		<< FCPPT_TEXT("How many children does the tree have: ")
		<< tree.size()
		<< FCPPT_TEXT('\n');

	// Outputs: hello world
	fcppt::io::cout()
		<< FCPPT_TEXT("The tree value is: ")
		<< tree.value()
		<< FCPPT_TEXT('\n');

	// Output the first level of the tree below the root.
	// Note that iterator::value_type is string_tree.
	for(
		string_tree::const_iterator it(
			tree.begin()
		);
		it != tree.end();
		++it
	)
		fcppt::io::cout()
			<< it->value()
			<< FCPPT_TEXT('\n');

	string_tree &first_child(
		tree.front()
	);

	fcppt::io::cout()
		<< FCPPT_TEXT("First child has a parent: ")
		<< first_child.has_parent()
		<< FCPPT_TEXT('\n');

	fcppt::io::cout()
		<< FCPPT_TEXT("First child's position in the parent's child list: ")
		<< std::distance(
			first_child.parent().begin(),
			first_child.child_position()
		)
		<< FCPPT_TEXT('\n');
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
//]
