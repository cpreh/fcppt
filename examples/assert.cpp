//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[assert
#include <fcppt/assert.hpp>
#include <fcppt/assert_message.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/text.hpp>

int main()
{
	try
	{
		FCPPT_ASSERT(
			false);
	}
	catch (fcppt::assertion_failed const &e)
	{
		fcppt::io::cerr
			<< FCPPT_TEXT("Assertion caught: ")
			<< e.string()
			<< FCPPT_TEXT("\n");
	}

	try
	{
		FCPPT_ASSERT_MESSAGE(
			false,
			FCPPT_TEXT("Hello World"));
	}
	catch (fcppt::assertion_failed const &e)
	{
		fcppt::io::cerr
			<< FCPPT_TEXT("Assertion caught: ")
			<< e.string()
			<< FCPPT_TEXT("\n");
	}
}
//]
