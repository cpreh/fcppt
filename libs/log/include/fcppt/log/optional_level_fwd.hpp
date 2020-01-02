//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_OPTIONAL_LEVEL_FWD_HPP_INCLUDED
#define FCPPT_LOG_OPTIONAL_LEVEL_FWD_HPP_INCLUDED

#include <fcppt/log/level_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace fcppt
{
namespace log
{

/**
\brief An optional level

\ingroup fcpptlog
*/
typedef
fcppt::optional::object<
	fcppt::log::level
>
optional_level;

}
}

#endif
