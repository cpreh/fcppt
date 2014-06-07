//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/narrow.hpp>
#include <fcppt/text.hpp>
#include <fcppt/widen.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <string>
#include <fcppt/config/external_end.hpp>


int main()
try
{
	std::wstring const test(
		L"localhöst 東方"
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

	if(
		back != test
	)
		fcppt::io::cerr()
			<< FCPPT_TEXT("Strings are not equal!\n");
	else
		fcppt::io::cerr()
			<< FCPPT_TEXT("Strings are equal!\n");
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
