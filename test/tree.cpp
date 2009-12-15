/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/



#include <fcppt/container/tree.hpp>
#include <fcppt/container/traversal.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/make_auto_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <ostream>
#include <cstdlib>

int main()
try
{
	typedef fcppt::container::tree<
		fcppt::string
	> string_tree;

	string_tree tree(
		FCPPT_TEXT("hello")
	);

	{
		string_tree::auto_ptr child1(
			fcppt::make_auto_ptr<
				string_tree
			>(
				FCPPT_TEXT("blubb")
			)
		);

		tree.push_back(
			child1
		);
	}

	{
		string_tree::auto_ptr child2(
			fcppt::make_auto_ptr<
				string_tree
			>(
				FCPPT_TEXT("blah")
			)
		);

		tree.push_back(
			child2
		);
	}

	tree.push_back(
		FCPPT_TEXT("foobar")
	);

	typedef
	fcppt::container::traversal<
		string_tree const
	> traversal_type;

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
