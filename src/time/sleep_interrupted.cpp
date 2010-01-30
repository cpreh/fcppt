//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/time/sleep_interrupted.hpp>
#include <fcppt/text.hpp>

fcppt::time::sleep_interrupted::sleep_interrupted()
:
	time::exception(
		FCPPT_TEXT("Sleep interrupted")
	)
{}
