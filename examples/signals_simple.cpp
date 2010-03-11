//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[signals_simple
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/tr1/functional.hpp>
#include <iostream>

namespace
{
struct foo {};

void callback(int i)
{
	std::cout << "\"callback\" called with " << i << "!\n";
}

void other_callback(foo &)
{
	std::cout << "\"other_callback\" called\n";
}
}

int main()
{
	typedef void function(int);

	fcppt::signal::object<function> s;

	// Connect function "callback" to signal
	fcppt::signal::scoped_connection connection(
		s.connect(&callback));
	
	// Call the signal, will output: "callback" called with 3
	s(3);

	// Define another function
	typedef void other_function(foo &);

	fcppt::signal::object<other_function> s2;

	fcppt::signal::scoped_connection connection2(
		s2.connect(
			&other_callback));
	
	foo f;
	// Note the use of std::tr1::ref because the signal gets a non-const reference
	// Outputs: "other_callback" called
	s2(std::tr1::ref(f));
}
//]
