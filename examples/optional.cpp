//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[optional
#include <fcppt/optional_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>


int main()
{
	// set the optional to "test"
	fcppt::optional_string opt1(
		FCPPT_TEXT("test")
	);

	// copy opt1 by value
	fcppt::optional_string opt2(
		opt1
	);

	fcppt::io::cout()
		<< *opt1
		<< FCPPT_TEXT('\n')
		<< *opt2
		<< FCPPT_TEXT('\n');

	opt2 = FCPPT_TEXT("test2");

	// assign opt1 by value
	opt1 = opt2;

	fcppt::io::cout()
		<< *opt1
		<< FCPPT_TEXT('\n')
		<< *opt2
		<< FCPPT_TEXT('\n');

	if(
		opt1
	)
		fcppt::io::cout()
			<< FCPPT_TEXT("opt1 is set\n");

	// destroy opt1's value
	opt1.reset();

	if(
		!opt1
	)
		fcppt::io::cout()
			<< FCPPT_TEXT("opt1 is not set\n");
}
//]
