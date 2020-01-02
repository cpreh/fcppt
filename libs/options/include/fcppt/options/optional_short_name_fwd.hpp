//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTIONAL_SHORT_NAME_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTIONAL_SHORT_NAME_FWD_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/options/short_name_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief An optional short name.

\ingroup fcpptoptions
*/
typedef
fcppt::optional::object<
	fcppt::options::short_name
>
optional_short_name;

}
}

#endif
