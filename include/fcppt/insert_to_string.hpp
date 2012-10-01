//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INSERT_TO_STRING_HPP_INCLUDED
#define FCPPT_INSERT_TO_STRING_HPP_INCLUDED

#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
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
\see fcppt::insert_to_std_string
\see fcppt::insert_to_std_wstring
\see fcppt::insert_to_fcppt_string
*/
template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	fcppt::type_traits::is_string<
		Dest
	>,
	Dest
>::type const
insert_to_string(
	Source const &_source,
	std::locale const &_locale
		= std::locale()
)
{
	typedef std::basic_ostringstream<
		typename Dest::value_type,
		typename Dest::traits_type
	> ostringstream;

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
