//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


namespace
{

void
something()
{
}

}

int
main()
{

{
//![literals]
char const chars[] = "foobar";
wchar_t const wchars[] = L"foobar";
//![literals]

	std::cout << chars << '\n';
	std::wcout << wchars << L'\n';
}

{

//![text_literal]
fcppt::string s(FCPPT_TEXT("foo"));
//![text_literal]

	fcppt::io::cout() << s << FCPPT_TEXT('\n');
}

//[exception]
try
{
	something();
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr() << _error.string() << FCPPT_TEXT('\n');
}
//[exception]
}
