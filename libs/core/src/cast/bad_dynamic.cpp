//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/type_name_from_index.hpp>
#include <fcppt/cast/bad_dynamic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeindex>
#include <fcppt/config/external_end.hpp>


fcppt::cast::bad_dynamic::bad_dynamic(
	std::type_index const &_source,
	std::type_index const &_destination
)
:
	fcppt::exception(
		FCPPT_TEXT("Invalid dynamic_cast from type \"")
		+
		fcppt::from_std_string(
			fcppt::type_name_from_index(
				_source
			)
		)
		+
		FCPPT_TEXT("\" to type \"")
		+
		fcppt::from_std_string(
			fcppt::type_name_from_index(
				_destination
			)
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

fcppt::cast::bad_dynamic::bad_dynamic(
	bad_dynamic const &
)
= default;

fcppt::cast::bad_dynamic::bad_dynamic(
	bad_dynamic &&
)
= default;

fcppt::cast::bad_dynamic &
fcppt::cast::bad_dynamic::operator=(
	bad_dynamic const &
)
= default;

fcppt::cast::bad_dynamic &
fcppt::cast::bad_dynamic::operator=(
	bad_dynamic &&
)
= default;

fcppt::cast::bad_dynamic::~bad_dynamic() noexcept
{
}

std::type_index const &
fcppt::cast::bad_dynamic::source() const
{
	return
		source_;
}

std::type_index const &
fcppt::cast::bad_dynamic::destination() const
{
	return
		destination_;
}
