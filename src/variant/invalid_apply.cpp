//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/invalid_apply.hpp>
#include <fcppt/text.hpp>

fcppt::variant::invalid_apply::invalid_apply()
:
	exception(
		FCPPT_TEXT("apply has been called on a variant that is empty!")
	)
{}
