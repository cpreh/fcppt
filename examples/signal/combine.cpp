//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [signal_combine]
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/auto_connection.hpp>


namespace
{
int first_callback()
{
	return 4;
}

int second_callback()
{
	return 8;
}

int third_callback()
{
	return 15;
}

int combiner(int const a,int const b)
{
	return a * b;
}
}

int main()
{
	typedef int function();

	typedef fcppt::signal::object<
		function
	> int_signal;

	// Pass the combiner here - can also be changed later
	int_signal signal(
		int_signal::combiner_function(
			&combiner
		),
		int_signal::initial_value{
			1
		}
	);

	fcppt::signal::auto_connection const connection1(
		signal.connect(
			int_signal::function{
				&first_callback
			}
		)
	);

	fcppt::signal::auto_connection const connection2(
		signal.connect(
			int_signal::function{
				&second_callback
			}
		)
	);

	fcppt::signal::auto_connection const connection3(
		signal.connect(
			int_signal::function{
				&third_callback
			}
		)
	);

	// Outputs ((1*4)*8)*15=480
	fcppt::io::cout()
		<< signal()
		<< FCPPT_TEXT('\n');
}
//! [signal_combine]
