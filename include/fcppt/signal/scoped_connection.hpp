//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_SCOPED_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_SCOPED_CONNECTION_HPP_INCLUDED

#include <fcppt/signal/connection_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace signal
{

/**
\brief A scoped pointer pointer to a connection
\ingroup fcpptsignal
*/
typedef
std::unique_ptr<
	fcppt::signal::connection
>
const
scoped_connection;

}
}

#endif
