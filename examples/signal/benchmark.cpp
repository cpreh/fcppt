//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#if defined(FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_FCPPT)
#include <fcppt/signal/auto_connection_container.hpp>
#include <fcppt/signal/object.hpp>
#elif defined(FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_BOOST_SIGNALS2)
#include <fcppt/config/external_begin.hpp>
#include <boost/signals2.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>
#else
#error "Wrong option"
#endif
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace
{
void f()
{
  static unsigned i = 0;
  if (++i % 10000 == 0)
  {
    std::cout << "|\n";
  }
}

std::size_t const max_iterations = 1000000;
}

int main()
try
{
#if defined(FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_FCPPT)
  using signal_type = fcppt::signal::object<void()>;

  signal_type s;

  fcppt::signal::auto_connection_container manager;

  for (std::size_t i = 0; i < max_iterations; ++i)
  {
    manager.push_back(s.connect(signal_type::function(&f)));
  }

  s();
#elif defined(FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_BOOST_SIGNALS2)
  using signal_type = boost::signals2::signal<void()>;

  signal_type s;

  using connection_manager = std::vector<boost::signals2::connection>;

  connection_manager manager;

  manager.reserve(max_iterations);

  for (std::size_t i = 0; i < max_iterations; ++i)
  {
    manager.push_back(s.connect(&f));
  }

  s();
#endif
}
catch (std::exception const &_error)
{
  std::cerr << _error.what() << '\n';

  return EXIT_FAILURE;
}
