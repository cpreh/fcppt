//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[signal_connection
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/connection_manager.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/signal/shared_connection.hpp>
#include <fcppt/assign/make_container.hpp>
//<-
namespace
{

void
function1()
{
}

void
function2()
{
}

void
function3()
{
}

void
function4()
{
}

void
function5()
{
}

}
//->

namespace
{

void
take_connection(
	fcppt::signal::auto_connection connection
)
{
	// do something with connection
//<-
	connection.reset();
//->
}

}

int main()
{
	typedef void function();

	typedef fcppt::signal::object<
		function
	> void_signal;

	void_signal signal;

	// use fcppt::assign::make_container to pass a container of connections
	fcppt::signal::connection_manager const connections(
		fcppt::assign::make_container<
			fcppt::signal::connection_manager::container
		>(
			fcppt::signal::shared_connection(
				signal.connect(
					::function1
				)
			)
		)
		(
			fcppt::signal::shared_connection(
				signal.connect(
					::function2
				)
			)
		)
	);

	// scoped_connection can also be used
	fcppt::signal::scoped_connection const connection3(
		signal.connect(
			::function3
		)
	);

	// or a shared_connection
	fcppt::signal::shared_connection const connection4(
		signal.connect(
			::function4
		)
	);

	// or you can take the auto_connection and process it somehow
	fcppt::signal::auto_connection connection5(
		signal.connect(
			::function5
		)
	);

	::take_connection(
		move(
			connection5
		)
	);
}
//]
