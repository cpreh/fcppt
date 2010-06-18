//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_IMPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_CHRONO_IMPL_EXCEPTION_HPP_INCLUDED

#include <fcppt/text.hpp>

inline
fcppt::chrono::exception::exception(
	fcppt::string const &s
)
:
	fcppt::exception(
		FCPPT_TEXT("chrono: ")
		+ s
	)
{}

#endif
