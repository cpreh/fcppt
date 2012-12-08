//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/connection_manager.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::signal::connection_manager::connection_manager()
:
	connections_()
{
}

fcppt::signal::connection_manager::connection_manager(
	container &&_connections
)
:
	connections_(
		std::move(
			_connections
		)
	)
{
}

fcppt::signal::connection_manager::~connection_manager()
{
}

void
fcppt::signal::connection_manager::add(
	fcppt::signal::auto_connection &&_con
)
{
	connections_.push_back(
		std::move(
			_con
		)
	);
}

void
fcppt::signal::connection_manager::assign(
	container &&_connections
)
{
	connections_ =
		std::move(
			_connections
		);
}

void
fcppt::signal::connection_manager::clear()
{
	connections_.clear();
}
