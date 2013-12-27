//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DEFINE_OBJECT_HPP_INCLUDED
#define FCPPT_LOG_DEFINE_OBJECT_HPP_INCLUDED

#include <fcppt/log/object.hpp>


/**
\brief Defines a logger function

\ingroup fcpptlog

A helper macro that defines a global logger function and its object.
If you have a function declaration
<code>%fcppt::log::object & mynamespace::logger();</code>
you can invoke this macro with:
<code>
%FCPPT_LOG_DEFINE_OBJECT(mynamespace::logger, constructor_parameters)
</code>

\param function The fully qualified function name of the function to define

\param parameters The parameters for the fcppt::log::object
*/
#define FCPPT_LOG_DEFINE_OBJECT(\
	function,\
	parameters\
)\
namespace \
{ \
\
fcppt::log::object fcppt_global_logger( \
	parameters \
); \
\
} \
\
fcppt::log::object & \
function ()\
{ \
	return fcppt_global_logger; \
}

#endif
