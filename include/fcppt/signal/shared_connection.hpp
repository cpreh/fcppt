//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_SHARED_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_SHARED_CONNECTION_HPP_INCLUDED

#include <fcppt/signal/detail/connection_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace fcppt
{
namespace signal
{
typedef shared_ptr<detail::connection> shared_connection;
}
}

#endif
