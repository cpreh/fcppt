//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[assert
#include <fcppt/assert/exception.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/assert/post_message.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>

//->
namespace
{
//<-

bool
other_function();

//<-
bool
other_function()
{
	return false;
}
//->

void
library_function(
	int const _parameter
)
{
	// assert a precondition without a message
	FCPPT_ASSERT_PRE(
		_parameter < 10
	)

	// assert a postcondition with a message
	FCPPT_ASSERT_POST_MESSAGE(
		other_function(),
		fcppt::assert_::exception,
		FCPPT_TEXT("other_function failed")
	)
}

//->
}

int main()
try
{
	library_function(
		5
	);
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');
}
//<-
//]
