//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DEFINE_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_DEFINE_CONTEXT_HPP_INCLUDED

#include <fcppt/log/context.hpp>


/**
\brief Defines a log context function

For a function

\code
namespace foo
{
fcppt::log::context &
context_name();
}
\endcode

the \a name parameter should be <code>foo::context_name</code>

\param name The name of the logger function including its namespaces
*/
#define FCPPT_LOG_DEFINE_CONTEXT(\
	name\
)\
fcppt::log::context & \
name()\
{\
	static fcppt::log::context ret;\
	\
	return ret; \
}

#endif
