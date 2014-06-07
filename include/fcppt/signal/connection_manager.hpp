//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_CONNECTION_MANAGER_HPP_INCLUDED
#define FCPPT_SIGNAL_CONNECTION_MANAGER_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/connection_manager_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace signal
{

class connection_manager
{
	FCPPT_NONCOPYABLE(
		connection_manager
	);

/*
	connection_manager(
		connection_manager const &
	) = delete;

	connection_manager &
	operator=(
		connection_manager const &
	) = delete;*/
public:
	typedef std::vector<
		fcppt::signal::auto_connection
	> container;

	FCPPT_SYMBOL
	connection_manager();

	FCPPT_SYMBOL
	explicit
	connection_manager(
		fcppt::signal::connection_manager::container &&
	);

	FCPPT_SYMBOL
	connection_manager(
		fcppt::signal::connection_manager &&
	);

	FCPPT_SYMBOL
	fcppt::signal::connection_manager &
	operator=(
		fcppt::signal::connection_manager &&
	);

	FCPPT_SYMBOL
	~connection_manager();

	FCPPT_SYMBOL
	void
	add(
		fcppt::signal::auto_connection &&
	);

	FCPPT_SYMBOL
	void
	assign(
		container &&
	);

	FCPPT_SYMBOL
	void
	clear();

	FCPPT_SYMBOL
	void
	swap(
		fcppt::signal::connection_manager &
	);
private:
	fcppt::signal::connection_manager::container connections_;
};

FCPPT_SYMBOL
void
swap(
	fcppt::signal::connection_manager &,
	fcppt::signal::connection_manager &
);

}
}

#endif
