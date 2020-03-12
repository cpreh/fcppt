//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OUTPUT_TO_STRING_LOCALE_HPP_INCLUDED
#define FCPPT_OUTPUT_TO_STRING_LOCALE_HPP_INCLUDED

#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <sstream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Convert an arbitrary type to a string, using a custom locale.

\ingroup fcpptstring

\tparam Dest A string type, see #fcppt::type_traits::is_string.

\tparam Source The type to make into a string. Has to have an <code>operator&lt;&lt;</code> defined.

\see fcppt::extract_from_string
\see fcppt::output_to_std_string
\see fcppt::output_to_std_wstring
\see fcppt::output_to_fcppt_string
*/
template<
	typename Dest,
	typename Source
>
Dest
output_to_string_locale(
	Source const &_source,
	std::locale const &_locale
)
{
	static_assert(
		fcppt::type_traits::is_string<
			Dest
		>::value,
		"insert_ot_string must return a string"
	);

	typedef
	std::basic_ostringstream<
		fcppt::type_traits::value_type<
			Dest
		>,
		typename
		Dest::traits_type
	>
	ostringstream;

	// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
	ostringstream oss{};

	oss.imbue(
		_locale
	);

	oss << _source;

	return
		oss.str();
}

}

#endif
