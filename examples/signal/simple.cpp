//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [signal_simple]
#include <fcppt/make_ref.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>


namespace
{

struct test_struct
{};

void
callback(
	int const _value
)
{
	fcppt::io::cout()
		<< FCPPT_TEXT("\"callback\" called with ")
		<< _value
		<< FCPPT_TEXT("!\n");
}

void
other_callback(
	test_struct &
)
{
	fcppt::io::cout()
		<< FCPPT_TEXT("\"other_callback\" called\n");
}

}

int
main()
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
		void(
			test_struct &
		)
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

	test_struct foo;
	// Outputs: "other_callback" called
	signal2(
		foo
	);
}
//! [signal_simple]
