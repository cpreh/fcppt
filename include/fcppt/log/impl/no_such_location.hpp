//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_IMPL_NO_SUCH_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_IMPL_NO_SUCH_LOCATION_HPP_INCLUDED

#include <fcppt/text.hpp>

inline
fcppt::log::no_such_location::no_such_location(
	log::location const &nlocation_
)
:
	exception(
		FCPPT_TEXT("no such location \"")
		+ nlocation_.string()
		+ FCPPT_TEXT('"')
	),
	location_(
		nlocation_
	)
{}

inline
fcppt::log::location const &
fcppt::log::no_such_location::location() const
{
	return location_;
}

#endif
