//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/element_not_found.hpp>
#include <fcppt/text.hpp>

fcppt::algorithm::element_not_found::element_not_found()
:
	exception(
		FCPPT_TEXT("element not found")
	)
{}
