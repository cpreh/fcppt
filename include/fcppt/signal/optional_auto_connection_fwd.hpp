//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_OPTIONAL_AUTO_CONNECTION_FWD_HPP_INCLUDED
#define FCPPT_SIGNAL_OPTIONAL_AUTO_CONNECTION_FWD_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>


namespace fcppt
{
namespace signal
{

/**
\brief An optional auto connection

\ingroup fcpptsignal
*/
typedef
fcppt::optional<
	fcppt::signal::auto_connection
>
optional_auto_connection;

}
}

#endif
