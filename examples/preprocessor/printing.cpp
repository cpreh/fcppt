//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[preprocessor_printing
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/preprocessor/file.hpp>
#include <fcppt/preprocessor/function.hpp>


namespace
{

void
some_function()
{
	fcppt::io::cout()
		<< FCPPT_PP_FILE
		<< FCPPT_TEXT(": ")
		<< FCPPT_PP_FUNCTION
		<< FCPPT_TEXT('\n');
}

}
//]

int main()
{
	some_function();
}
