//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_HELP_SWITCH_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_HELP_SWITCH_FWD_HPP_INCLUDED

#include <fcppt/options/unit_switch_fwd.hpp>
#include <fcppt/options/detail/help_label.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The type of a help parser.

\ingroup fcpptoptions

A help parser is a switch used to display a help message.
*/
using
help_switch
=
fcppt::options::unit_switch<
	fcppt::options::detail::help_label
>;

}
}

#endif
