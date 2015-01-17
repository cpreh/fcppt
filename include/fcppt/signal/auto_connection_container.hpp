//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_AUTO_CONNECTION_CONTAINER_HPP_INCLUDED
#define FCPPT_SIGNAL_AUTO_CONNECTION_CONTAINER_HPP_INCLUDED

#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace signal
{

typedef
std::vector<
	fcppt::signal::auto_connection
>
auto_connection_container;

}
}

#endif
