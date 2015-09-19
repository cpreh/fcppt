//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [signal_simple]
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/auto_connection.hpp>


namespace
{

struct foo
{};

void
callback(
	int const i
)
{
	fcppt::io::cout()
		<< FCPPT_TEXT("\"callback\" called with ")
		<< i
		<< FCPPT_TEXT("!\n");
}

void
other_callback(
	foo &
)
{
	fcppt::io::cout()
		<< FCPPT_TEXT("\"other_callback\" called\n");
}

}

int main()
{
	typedef
	fcppt::signal::object<
		void (int)
	>
	signal_type;

	signal_type signal;

	// Connect function "callback" to signal
	fcppt::signal::auto_connection const connection(
		signal.connect(
			signal_type::function{
				&callback
			}
		)
	);

	// Call the signal, will output: "callback" called with 3
	signal(3);

	// Define another function
	typedef
	fcppt::signal::object<
		void (foo &)
	>
	signal2_type;

	signal2_type signal2;

	fcppt::signal::auto_connection const connection2(
		signal2.connect(
			signal2_type::function{
				&other_callback
			}
		)
	);

	foo my_foo;
	// Note the use of fcppt::ref because the signal gets a non-const reference
	// Outputs: "other_callback" called
	signal2(
		my_foo
	);
}
//! [signal_simple]
