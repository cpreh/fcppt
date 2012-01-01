//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_IMPL_ELEMENT_NOT_FOUND_HPP_INCLUDED
#define FCPPT_ALGORITHM_IMPL_ELEMENT_NOT_FOUND_HPP_INCLUDED

#include <fcppt/text.hpp>

inline
fcppt::algorithm::element_not_found::element_not_found()
:
	algorithm::exception(
		FCPPT_TEXT("element not found")
	)
{}

#endif
