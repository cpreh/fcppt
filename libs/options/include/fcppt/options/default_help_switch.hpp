//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DEFAULT_HELP_SWITCH_HPP_INCLUDED
#define FCPPT_OPTIONS_DEFAULT_HELP_SWITCH_HPP_INCLUDED

#include <fcppt/options/help_switch.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The default help switch.

\ingroup fcpptoptions

The default help switch that use "-h" or "--help".
*/
FCPPT_OPTIONS_DETAIL_SYMBOL
fcppt::options::help_switch
default_help_switch();

}
}

#endif
