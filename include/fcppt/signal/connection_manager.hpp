//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_CONNECTION_MANAGER_HPP_INCLUDED
#define FCPPT_SIGNAL_CONNECTION_MANAGER_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/connection_manager_fwd.hpp>
#include <fcppt/signal/shared_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
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
public:
	typedef std::vector<
		shared_connection
	> container;

	FCPPT_SYMBOL connection_manager();

	FCPPT_SYMBOL explicit connection_manager(
		container const &
	);

	FCPPT_SYMBOL ~connection_manager();

	FCPPT_SYMBOL
	void
	add(
		auto_connection
	);

	FCPPT_SYMBOL
	void
	assign(
		container const &
	);

	FCPPT_SYMBOL void
	clear();
private:
	container connections_;
};

}
}

#endif
