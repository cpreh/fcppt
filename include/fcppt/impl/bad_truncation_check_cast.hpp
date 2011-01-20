//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPL_BAD_TRUNCATION_CHECK_CAST_HPP_INCLUDED
#define FCPPT_IMPL_BAD_TRUNCATION_CHECK_CAST_HPP_INCLUDED

#include <fcppt/text.hpp>

inline
fcppt::bad_truncation_check_cast::bad_truncation_check_cast(
	fcppt::type_info const &_source,
	fcppt::type_info const &_destination
)
:
	exception(
		FCPPT_TEXT("Invalid truncation_check_cast from type \"")+
		_source.name()+
		FCPPT_TEXT("\" to type \"")+
		_destination.name()+
		FCPPT_TEXT('"')
	),
	source_(_source),
	destination_(_destination)
{
}

inline
fcppt::type_info const &
fcppt::bad_truncation_check_cast::source() const
{
	return source_;
}

inline
fcppt::type_info const &
fcppt::bad_truncation_check_cast::destination() const
{
	return destination_;
}

#endif
