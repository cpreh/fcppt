//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_IMPL_INVALID_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_IMPL_INVALID_APPLY_HPP_INCLUDED

#include <fcppt/text.hpp>

inline
fcppt::variant::invalid_apply::invalid_apply()
:
	exception(
		FCPPT_TEXT("apply has been called on a variant that is empty!")
	)
{}

#endif
