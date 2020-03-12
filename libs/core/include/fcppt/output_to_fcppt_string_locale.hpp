//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OUTPUT_TO_FCPPT_STRING_LOCALE_HPP_INCLUDED
#define FCPPT_OUTPUT_TO_FCPPT_STRING_LOCALE_HPP_INCLUDED

#include <fcppt/output_to_string_locale.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Converts an arbitrary type to a #fcppt::string, using a custom locale.

\ingroup fcpptstring

\tparam Source The type to make into a string. Has to have an <code>operator&lt;&lt;</code> defined.

\see fcppt::extract_from_string
\see fcppt::output_to_string
\see fcppt::output_to_std_string
\see fcppt::output_to_std_wstring
*/
template<
	typename Source
>
fcppt::string
output_to_fcppt_string_locale(
	Source const &_source,
	std::locale const &_locale
)
{
	return
		fcppt::output_to_string_locale<
			fcppt::string
		>(
			_source,
			_locale
		);
}

}

#endif
