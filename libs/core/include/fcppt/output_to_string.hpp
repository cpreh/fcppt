//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OUTPUT_TO_STRING_HPP_INCLUDED
#define FCPPT_OUTPUT_TO_STRING_HPP_INCLUDED

#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Convert an arbitrary type to a string
\tparam Dest A string type, see fcppt::type_traits::is_string
\tparam Source The type to make into a string. Has to have an <code>operator&lt;&lt;</code> defined.
\param _source The object to convert
\param _locale The locale (defaults to the C locale)
\ingroup fcpptstring

Note that the default locale for this function is the C locale. This is
consistent with the fcppt::extract_from_string function. See this function to
see why this locale was chosen.

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
output_to_string(
	Source const &_source,
	std::locale const &_locale
		= std::locale()
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
		typename Dest::traits_type
	>
	ostringstream;

	ostringstream oss;

	oss.imbue(
		_locale
	);

	oss << _source;

	return
		oss.str();
}

}

#endif
