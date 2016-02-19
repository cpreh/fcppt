//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_IMPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_LOG_IMPL_EXCEPTION_HPP_INCLUDED

#include <fcppt/text.hpp>

inline
fcppt::log::exception::exception(
	fcppt::string const &what_
)
:
	fcppt::exception(
		FCPPT_TEXT("log: ")
		+ what_
	)
{}

#endif
