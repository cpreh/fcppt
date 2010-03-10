//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <iostream>
#include <ostream>

int main()
{
	fcppt::string const s(FCPPT_TEXT("test"));
	std::string const converted = fcppt::to_std_string(s);
	std::cout << converted << "\n";
	fcppt::io::cout << fcppt::from_std_string(converted) << FCPPT_TEXT("\n");
	// FIXME: fcppt::string -> std::wstring?
}

//]
