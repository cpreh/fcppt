//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OTHER_ERROR_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_OTHER_ERROR_FWD_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/string.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A string type representing other errors.

\ingroup fcpptoptions

Errors that are not #fcppt::options::missing_error, for example
failed conversion. Such errors make even #fcppt::options::optional parsers fail.
*/
FCPPT_MAKE_STRONG_TYPEDEF(
	fcppt::string,
	other_error
);

}
}

#endif
