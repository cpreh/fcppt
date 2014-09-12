//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_IMPL_BAD_DYNAMIC_HPP_INCLUDED
#define FCPPT_CAST_IMPL_BAD_DYNAMIC_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/type_name_from_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeindex>
#include <fcppt/config/external_end.hpp>


inline
fcppt::cast::bad_dynamic::bad_dynamic(
	std::type_index const &_source,
	std::type_index const &_destination
)
:
	fcppt::exception(
		FCPPT_TEXT("Invalid dynamic_cast from type \"")
		+
		fcppt::type_name_from_index(
			_source
		)
		+
		FCPPT_TEXT("\" to type \"")
		+
		fcppt::type_name_from_index(
			_destination
		)
		+
		FCPPT_TEXT('"')
	),
	source_(
		_source
	),
	destination_(
		_destination
	)
{
}

inline
std::type_index const &
fcppt::cast::bad_dynamic::source() const
{
	return
		source_;
}

inline
std::type_index const &
fcppt::cast::bad_dynamic::destination() const
{
	return
		destination_;
}

#endif
