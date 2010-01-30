//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/cerr.hpp>
#include <fcppt/narrow.hpp>
#include <fcppt/widen.hpp>
#include <fcppt/text.hpp>
#include <fcppt/exception.hpp>
#include <string>
#include <cstdlib>

int main()
try
{
	std::wstring const test(
		L"localhost"
	);

	std::string const narrow(
		fcppt::narrow(
			test
		)
	);

	std::wstring const back(
		fcppt::widen(
			narrow
		)
	);

	if(back != test)
		fcppt::io::cerr << FCPPT_TEXT("Strings are not equal!\n");
	else
		fcppt::io::cerr << FCPPT_TEXT("Strings are equal!\n");
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
