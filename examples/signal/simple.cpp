//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [signal_simple]
struct test_struct
{};

void
callback(int const _value)
{
	fcppt::io::cout()
		<< FCPPT_TEXT("\"callback\" called with ")
		<< _value
		<< FCPPT_TEXT("!\n");
}

void
other_callback(fcppt::reference<test_struct>)
{
	fcppt::io::cout()
		<< FCPPT_TEXT("\"other_callback\" called\n");
}

void
main_example()
{
	using signal_type =
	fcppt::signal::object<
		void (int)
	>;

	signal_type signal{};

	// Connect function "callback" to signal
	fcppt::signal::auto_connection const connection(
		signal.connect(signal_type::function{&callback})
	);

	// Call the signal, will output: "callback" called with 3
	signal(3);

	// Define another function
	using signal2_type =
	fcppt::signal::object<
		void(fcppt::reference<test_struct>)
	>;

	signal2_type signal2{};

	fcppt::signal::auto_connection const connection2(
		signal2.connect(signal2_type::function{&other_callback})
	);

	test_struct foo{};
	// Outputs: "other_callback" called
	signal2(fcppt::make_ref(foo));
}
//! [signal_simple]

}

int
main()
try
{
	main_example();

	return
		EXIT_SUCCESS;
}
catch(
	std::exception const &_error
)
{
	std::cerr
		<<
		_error.what()
		<<
		'\n';

	return
		EXIT_FAILURE;
}
