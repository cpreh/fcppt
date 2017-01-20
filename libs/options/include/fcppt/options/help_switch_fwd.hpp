//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_HELP_SWITCH_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_HELP_SWITCH_FWD_HPP_INCLUDED

#include <fcppt/options/switch_fwd.hpp>
#include <fcppt/options/detail/help_label.hpp>


namespace fcppt
{
namespace options
{

typedef
fcppt::options::switch_<
	fcppt::options::detail::help_label
>
help_switch;

}
}

#endif
