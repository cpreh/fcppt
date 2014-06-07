//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
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

fcppt::signal::connection_manager::connection_manager(
	fcppt::signal::connection_manager &&_other
)
:
	connections_()
{
	_other.swap(
		*this
	);
}

fcppt::signal::connection_manager &
fcppt::signal::connection_manager::operator=(
	fcppt::signal::connection_manager &&_other
)
{
	_other.swap(
		*this
	);

	return *this;
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

void
fcppt::signal::connection_manager::swap(
	fcppt::signal::connection_manager &_other
)
{
	_other.connections_.swap(
		connections_
	);
}

void
fcppt::signal::swap(
	fcppt::signal::connection_manager &_a,
	fcppt::signal::connection_manager &_b
)
{
	_a.swap(
		_b
	);
}
