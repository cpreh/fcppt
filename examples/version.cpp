//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/version_string.hpp>
#include <fcppt/io/cout.hpp>


int main()
{
	fcppt::io::cout()
		<< FCPPT_TEXT("Current version is ")
		<< fcppt::version_string()
		<< FCPPT_TEXT('\n');
}
