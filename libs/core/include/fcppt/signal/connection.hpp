//          Copyright Carl Philipp Reh 2009 - 2016.
//          Copyright Philipp Middendorf 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_CONNECTION_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/detail/connection_base.hpp>


namespace fcppt
{
namespace signal
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)
FCPPT_PP_DISABLE_GCC_WARNING(-Wnon-virtual-dtor)

/**
\brief A connection returned by a connect call

\ingroup fcpptsignal

This class must be held onto as long as the connection to the signal should be
established.
*/
class connection
:
	public fcppt::signal::detail::connection_base
{
	FCPPT_NONCOPYABLE(
		connection
	);
public:
	connection();

	virtual
	~connection() = 0;
};

FCPPT_PP_POP_WARNING

}
}

#include <fcppt/signal/impl/connection.hpp>

#endif
