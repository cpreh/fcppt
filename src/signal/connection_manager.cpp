//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/signal/connection_manager.hpp>
#include <fcppt/move.hpp>

fcppt::signal::connection_manager::connection_manager()
:
	connections_()
{
}

fcppt::signal::connection_manager::connection_manager(
	container const &_connections
)
:
	connections_(_connections)
{}

fcppt::signal::connection_manager::~connection_manager()
{
}

void
fcppt::signal::connection_manager::connect(
	auto_connection _con
)
{
	connections_.push_back(
		shared_connection(
			move(
				_con
			)
		)
	);
}

void
fcppt::signal::connection_manager::clear()
{
	connections_.clear();
}
