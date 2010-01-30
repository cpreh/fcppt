//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/cout.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>

int main()
{
	typedef fcppt::optional<
		fcppt::string
	> optional_string;

	optional_string opt1(
		FCPPT_TEXT("test")
	);

	optional_string opt2(
		opt1
	);

	fcppt::io::cout
		<< *opt1
		<< FCPPT_TEXT('\n')
		<< *opt2
		<< FCPPT_TEXT('\n');

	opt2 = FCPPT_TEXT("test2");
	opt1 = opt2;

	fcppt::io::cout
		<< *opt1
		<< FCPPT_TEXT('\n')
		<< *opt2
		<< FCPPT_TEXT('\n');

	if(opt1)
		fcppt::io::cout << FCPPT_TEXT("opt1 is set\n");

	opt1.reset();

	if(!opt1)
		fcppt::io::cout << FCPPT_TEXT("opt1 is not set\n");
}
