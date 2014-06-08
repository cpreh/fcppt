//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifdef FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_FCPPT
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/auto_connection_container.hpp>
#elif defined(FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_BOOST_SIGNALS1)
#include <fcppt/config/external_begin.hpp>
#include <boost/signals.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>
#elif defined(FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_BOOST_SIGNALS2)
#include <fcppt/config/external_begin.hpp>
#include <boost/signals2.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>
#else
#error "Wtf"
#endif
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace
{
void
f()
{
	static unsigned i = 0;
	if(++i % 10000 == 0)
		std::cout << "|\n";
}

std::size_t const max_iterations = 1000000;
}

int
main()
{
#ifdef FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_FCPPT
	typedef
	fcppt::signal::object<void()>
	signal_type;

	signal_type s;

	fcppt::signal::auto_connection_container manager;

	for(std::size_t i = 0; i < max_iterations; ++i)
		manager.push_back(
			s.connect(
				&f));

	s();
#elif defined(FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_BOOST_SIGNALS1)
	typedef
	boost::signal<void()>
	signal_type;

	signal_type s;

	typedef
	std::vector<boost::signals::connection>
	connection_manager;

	connection_manager manager;

	manager.reserve(
		max_iterations);

	for(std::size_t i = 0; i < max_iterations; ++i)
		manager.push_back(
			s.connect(
				&f));

	s();
#elif defined(FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_BOOST_SIGNALS2)
	typedef
	boost::signals2::signal<void()>
	signal_type;

	signal_type s;

	typedef
	std::vector<boost::signals2::connection>
	connection_manager;

	connection_manager manager;

	manager.reserve(
		max_iterations);

	for(std::size_t i = 0; i < max_iterations; ++i)
		manager.push_back(
			s.connect(
				&f));

	s();
#endif
}
