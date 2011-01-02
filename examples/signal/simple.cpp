//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[signal_simple
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/text.hpp>

namespace
{

struct foo
{};

void
callback(
	int const i
)
{
	fcppt::io::cout
		<< FCPPT_TEXT("\"callback\" called with ")
		<< i
		<< FCPPT_TEXT("!\n");
}

void
other_callback(
	foo &
)
{
	fcppt::io::cout
		<< FCPPT_TEXT("\"other_callback\" called\n");
}

}

int main()
{
	typedef void function(int);

	fcppt::signal::object<function> signal;

	// Connect function "callback" to signal
	fcppt::signal::scoped_connection connection(
		signal.connect(
			&callback
		)
	);
	
	// Call the signal, will output: "callback" called with 3
	signal(3);

	// Define another function
	typedef void other_function(foo &);

	fcppt::signal::object<other_function> signal2;

	fcppt::signal::scoped_connection connection2(
		signal2.connect(
			&other_callback
		)
	);
	
	foo my_foo;
	// Note the use of std::tr1::ref because the signal gets a non-const reference
	// Outputs: "other_callback" called
	signal2(
		std::tr1::ref(
			my_foo
		)
	);
}
//]
