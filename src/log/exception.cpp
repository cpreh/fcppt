//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/exception.hpp>
#include <fcppt/text.hpp>

fcppt::log::exception::exception(
	fcppt::string const &what_
)
:
	fcppt::exception(
		FCPPT_TEXT("log: ")
		+ what_
	)
{}
