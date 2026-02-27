//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//! [signal_combine]
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <fcppt/config/external_end.hpp>

namespace
{
int first_callback() { return 4; }

int second_callback() { return 8; }

int third_callback() { return 15; }

int combiner(int const a, int const b) { return a * b; }

}

int main()
try
{
  using function = int();

  using int_signal = fcppt::signal::object<function>;

  int_signal signal{int_signal::combiner_function(&combiner)};

  fcppt::signal::auto_connection const connection1{
      signal.connect(int_signal::function{&first_callback})};

  fcppt::signal::auto_connection const connection2{
      signal.connect(int_signal::function{&second_callback})};

  fcppt::signal::auto_connection const connection3{
      signal.connect(int_signal::function{&third_callback})};

  // Outputs ((1*4)*8)*15=480
  std::cout << signal(int_signal::initial_value{1}) << '\n';

  return EXIT_SUCCESS;
}
catch(std::exception const &_error)
{
  std::cerr << _error.what() << '\n';
  return EXIT_FAILURE;
}
//! [signal_combine]
