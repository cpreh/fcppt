//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPL_EXTRACT_FROM_STRING_ERROR_HPP_INCLUDED
#define FCPPT_IMPL_EXTRACT_FROM_STRING_ERROR_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>

inline
fcppt::extract_from_string_error::extract_from_string_error()
:
	fcppt::exception(
		FCPPT_TEXT("fcppt::extract_from_string_exn() failed!")
	)
{
}

#endif
