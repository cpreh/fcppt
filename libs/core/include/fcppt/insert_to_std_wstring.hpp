//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INSERT_TO_STD_WSTRING_HPP_INCLUDED
#define FCPPT_INSERT_TO_STD_WSTRING_HPP_INCLUDED

#include <fcppt/insert_to_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Convert an arbitrary type to a std::wstring
\tparam Source The type to make into a string. Has to have an <code>operator&lt;&lt;</code> defined.
\param _source The object to convert
\param _locale The locale (defaults to the C locale)
\ingroup fcpptstring

Note that the default locale for this function is the C locale. This is
consistent with the fcppt::extract_from_string function. See this function to
see why this locale was chosen.

\see fcppt::extract_from_string
\see fcppt::insert_to_string
\see fcppt::insert_to_fcppt_string
\see fcppt::insert_to_std_string
*/
template<
	typename Source
>
std::wstring
insert_to_std_wstring(
	Source const &_source,
	std::locale const &_locale
		= std::locale()
)
{
	return
		fcppt::insert_to_string<
			std::wstring
		>(
			_source,
			_locale
		);
}

}

#endif
