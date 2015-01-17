//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/io/scoped_rdbuf.hpp>


int
main()
{
	fcppt::io::ostringstream ostream;

	{
		fcppt::io::scoped_rdbuf const scoped(
			ostream,
			fcppt::io::cout()
		);

		fcppt::io::cout()
			<< FCPPT_TEXT("This is a test!\n");
	}

	fcppt::io::cout()
		<< ostream.str();
}
