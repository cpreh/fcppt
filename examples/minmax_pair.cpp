//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[minmax_pair
#include <fcppt/minmax_pair.hpp>
#include <fcppt/invalid_minmax_pair.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

int main()
{

	typedef fcppt::minmax_pair<
		int
	> int_pair;

	int_pair test1(
		5,
		10
	);

	fcppt::io::cout()
		<< test1
		<< FCPPT_TEXT('\n');

	try
	{
		int_pair test2(
			100,
			50
		);
	}
	catch(
		fcppt::invalid_minmax_pair const &e
	)
	{
		fcppt::io::cout()
			<< e.string()
			<< FCPPT_TEXT('\n');
	}
}
//]
