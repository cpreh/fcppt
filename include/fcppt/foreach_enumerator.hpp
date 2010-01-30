//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FOREACH_ENUMERATOR_HPP_INCLUDED
#define FCPPT_FOREACH_ENUMERATOR_HPP_INCLUDED

#include <fcppt/foreach_enumerator_start.hpp>

#define FCPPT_FOREACH_ENUMERATOR(name, enum_)\
	FCPPT_FOREACH_ENUMERATOR_START(name, enum_, static_cast<enum_::type>(0))

#endif
