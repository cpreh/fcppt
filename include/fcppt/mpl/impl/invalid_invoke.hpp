//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/mpl/invalid_invoke.hpp>
#include <fcppt/text.hpp>

fcppt::mpl::invalid_invoke::invalid_invoke()
:
	fcppt::exception(
		FCPPT_TEXT("Invalid invoke!")
	)
{}
