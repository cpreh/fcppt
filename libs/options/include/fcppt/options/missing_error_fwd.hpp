//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MISSING_ERROR_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_MISSING_ERROR_FWD_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/string.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A string type representing a missing error.

\ingroup fcpptoptions

A missing error is an error that occurs if a required argument or option has
not been specified. Such an error makes \link fcppt::options::optional\endlink
parsers return an empty optional.
*/
FCPPT_MAKE_STRONG_TYPEDEF(
	fcppt::string,
	missing_error
);

}
}

#endif
