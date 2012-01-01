//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_IMPL_CLOCK_FAILURE_HPP_INCLUDED
#define FCPPT_CHRONO_IMPL_CLOCK_FAILURE_HPP_INCLUDED

inline
fcppt::chrono::clock_failure::clock_failure(
	fcppt::string const &e
)
:
	chrono::exception(
		e
	)
{}

#endif
