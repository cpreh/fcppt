//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_IS_OPTION_HPP_INCLUDED
#define FCPPT_OPTIONS_IS_OPTION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Checks if a string is an option

\ingroup fcpptoptions

Options are strings that with a '-'.
*/
FCPPT_OPTIONS_DETAIL_SYMBOL
bool
is_option(
	fcppt::string const &
);

}
}

#endif
