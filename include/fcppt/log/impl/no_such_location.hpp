//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_IMPL_NO_SUCH_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_IMPL_NO_SUCH_LOCATION_HPP_INCLUDED

#include <fcppt/text.hpp>

inline
fcppt::log::no_such_location::no_such_location(
	log::location const &_location
)
:
	exception(
		FCPPT_TEXT("no such location \"")
		+ _location.string()
		+ FCPPT_TEXT('"')
	),
	location_(
		_location
	)
{}

inline
fcppt::log::location const &
fcppt::log::no_such_location::location() const
{
	return location_;
}

inline
fcppt::log::no_such_location::~no_such_location() throw()
{
}

#endif
