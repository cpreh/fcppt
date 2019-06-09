//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MISSING_ERROR_HPP_INCLUDED
#define FCPPT_OPTIONS_MISSING_ERROR_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/missing_error_fwd.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/symbol.hpp>


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
struct missing_error
{
	FCPPT_OPTIONS_DETAIL_SYMBOL
	missing_error(
		fcppt::options::state &&,
		fcppt::string &&
	);

	fcppt::options::state state_;

	fcppt::string error_;
};

}
}

#endif
