//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/field.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <exception>
#include <iostream>
#include <ostream>
#include <vector>
#include <cstdlib>

int main()
try
{
	typedef fcppt::container::field<
		std::vector<
			int
		>
	> field_type;

	field_type f(
		field_type::dim(
			2,2
		)
	);

	f.pos(field_type::vector(0,0)) = 0;
	f.pos(field_type::vector(1,0)) = 1;
	f.pos(field_type::vector(0,1)) = 2;
	f.pos(field_type::vector(1,1)) = 3;
	
	fcppt::io::cout
		<< f
		<< FCPPT_TEXT('\n');

	f.resize_canvas(
		field_type::dim(
			1,
			1
		),
		9
	);
	
	fcppt::io::cout
		<< f
		<< FCPPT_TEXT('\n');
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< FCPPT_TEXT("caught fcppt exception: ")
		<< e.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
catch(
	std::exception const &e
)
{
	std::cerr
		<< "caught std exception: "
		<< e.what()
		<< '\n';

	return EXIT_FAILURE;
}
catch(...)
{
	std::cerr << "caught unknown exception\n";

	return EXIT_FAILURE;
}
