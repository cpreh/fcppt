//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [signal_connection]
#include <fcppt/container/make.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/auto_connection_container.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


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

}

namespace
{

void
take_connection(
	fcppt::signal::auto_connection
)
{
	// do something with connection
}

}

int
main()
{
	typedef fcppt::signal::object<
		void ()
	> void_signal;

	void_signal signal;

	// use fcppt::container::make to pass a container of connections
	fcppt::signal::auto_connection_container const connections(
		fcppt::container::make<
			fcppt::signal::auto_connection_container
		>(
			signal.connect(
				void_signal::function{
					::function1
				}
			),
			signal.connect(
				void_signal::function{
					::function2
				}
			)
		)
	);

	// or you can take the auto_connection and process it somehow
	fcppt::signal::auto_connection connection4(
		signal.connect(
			void_signal::function{
				::function3
			}
		)
	);

	::take_connection(
		std::move(
			connection4
		)
	);
}
//! [signal_connection]
