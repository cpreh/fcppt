//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/preprocessor/file.hpp>
#include <fcppt/preprocessor/function.hpp>


namespace
{

//! [pp_printing]
void
some_function()
{
	fcppt::io::cout()
		<< FCPPT_PP_FILE
		<< FCPPT_TEXT(':')
		<< __LINE__
		<< FCPPT_TEXT(": ")
		<< FCPPT_PP_FUNCTION
		<< FCPPT_TEXT('\n');
}
//! [pp_printing]

}

int
main()
{
	some_function();
}
