//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_IMPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_IMPL_EXCEPTION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>


inline
fcppt::algorithm::exception::exception(
	fcppt::string const &_text
)
:
	fcppt::exception(
		FCPPT_TEXT("algorithm: ")
		+ _text
	)
{}

#endif
