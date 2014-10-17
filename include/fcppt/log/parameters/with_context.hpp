//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_PARAMETERS_WITH_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_WITH_CONTEXT_HPP_INCLUDED

#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/symbol.hpp>
#include <fcppt/log/parameters/object.hpp>


namespace fcppt
{
namespace log
{
namespace parameters
{

/**
\brief A helper function to create parameters with a context and location

\ingroup fcpptlog

Creates a default constructed \link fcppt::log::parameters::object \endlink,
which then gets a context and location denoted by \a context and \a location,
as if by calling
<code>param.context_location(fcppt::log::context_location(context,
location))</code>.

\param context The context to use

\param location The location in the context

\return The constructed parameters class
*/
FCPPT_LOG_SYMBOL
fcppt::log::parameters::object
with_context(
	fcppt::log::context &context,
	fcppt::log::location const &location
);

}
}
}

#endif
