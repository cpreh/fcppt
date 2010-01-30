//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/signal/connection_manager.hpp>

fcppt::signal::connection_manager::connection_manager()
:
	connections()
{}

fcppt::signal::connection_manager::connection_manager(
	container const &_connections)
:
	connections(_connections)
{}

void fcppt::signal::connection_manager::connect(
	shared_connection const &v)
{
	connections.push_back(
		v);
}

void fcppt::signal::connection_manager::connect(
	auto_connection v)
{
	connections.push_back(
		shared_connection(
			v));
}

void fcppt::signal::connection_manager::clear()
{
	connections.clear();
}
