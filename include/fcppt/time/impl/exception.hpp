//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_IMPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_TIME_IMPL_EXCEPTION_HPP_INCLUDED

#include <fcppt/text.hpp>

inline
fcppt::time::exception::exception(
	fcppt::string const &s
)
:
	fcppt::exception(
		FCPPT_TEXT("time: ")
		+ s
	)
{}

#endif
