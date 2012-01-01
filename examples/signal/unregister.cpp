//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[signal_unregister
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/signal/unregister/base.hpp>
#include <fcppt/tr1/functional.hpp>


namespace
{

void
dummy_function()
{
}

void
on_unregister(
	int const _value
)
{
	fcppt::io::cout()
		<< FCPPT_TEXT("Connection destroyed ")
		<< _value
		<< FCPPT_TEXT(".\n");
}

}

int main()
{
	typedef void function();

	// Tell the signal to use deregistration
	typedef fcppt::signal::object<
		function,
		fcppt::signal::unregister::base
	> unregister_void_signal;

	unregister_void_signal signal;

	{
		// connect the function and unregister_callback
		fcppt::signal::scoped_connection const connection(
			signal.connect(
				::dummy_function,
				std::tr1::bind(
					::on_unregister,
					42
				)
			)
		);

		// The destructor of connection will cause on_unregister(42) to be called
	}

	fcppt::io::cout()
		<< FCPPT_TEXT("After destruction.\n");
}
//]
