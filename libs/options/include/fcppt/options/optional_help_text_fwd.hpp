//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_OPTIONAL_HELP_TEXT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTIONAL_HELP_TEXT_FWD_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/options/help_text_fwd.hpp>

namespace fcppt::options
{
/**
\brief An optional help text.

\ingroup fcpptoptions
*/
using optional_help_text = fcppt::optional::object<fcppt::options::help_text>;

}

#endif
