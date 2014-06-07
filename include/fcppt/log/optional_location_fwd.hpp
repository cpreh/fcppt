//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_OPTIONAL_LOCATION_FWD_HPP_INCLUDED
#define FCPPT_LOG_OPTIONAL_LOCATION_FWD_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>


namespace fcppt
{
namespace log
{

/**
\brief An optional location

\ingroup fcpptlog
*/
typedef fcppt::optional<
	fcppt::log::location
> optional_location;

}
}

#endif
