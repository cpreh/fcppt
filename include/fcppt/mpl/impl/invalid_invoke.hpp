//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_IMPL_INVALID_INVOKE_HPP_INCLUDED
#define FCPPT_MPL_IMPL_INVALID_INVOKE_HPP_INCLUDED

#include <fcppt/text.hpp>

inline
fcppt::mpl::invalid_invoke::invalid_invoke()
:
	mpl::exception(
		FCPPT_TEXT("Invalid invoke!")
	)
{}

#endif
