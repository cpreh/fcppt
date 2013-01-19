//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DEFINE_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_DEFINE_CONTEXT_HPP_INCLUDED

#include <fcppt/log/context.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


/**
\brief Defines a log context function

\ingroup fcpptlog

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
FCPPT_PP_PUSH_WARNING \
FCPPT_PP_DISABLE_VC_WARNING(4640) \
fcppt::log::context & \
name()\
{\
	static fcppt::log::context ret;\
	\
	return ret; \
} \
FCPPT_PP_POP_WARNING

#endif
