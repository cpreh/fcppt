//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_IMPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_FILESYSTEM_IMPL_EXCEPTION_HPP_INCLUDED

#include <fcppt/filesystem/exception.hpp>

inline
fcppt::filesystem::exception::exception(
	fcppt::string const &_what
)
:
	fcppt::exception(
		_what
	)
{}

#endif
