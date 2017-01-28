//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXTRACT_FROM_STRING_HPP_INCLUDED
#define FCPPT_EXTRACT_FROM_STRING_HPP_INCLUDED

#include <fcppt/io/extract.hpp>
#include <fcppt/optional/nothing.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Convert a string to a different type using a locale

\ingroup fcpptstring

\tparam Dest The destination type, has to have an <code>operator>></code> defined. Must
have either a default constructor or must be constructible from \link fcppt::no_init\endlink.

\tparam Source A string type (see \link fcppt::type_traits::is_string\endlink)

\param _source The string to extract from

\param _locale The locale to use (defaults to <code>std::locale()</code>)

Note that the string has to be consumed completely.

Also note that the default locale for this function is the C locale. This was
chosen deliberately to avoid confusion when converting, for example, "300,100"
to int. Using the C locale, this will fail, since the string isn't completely
consumed. Using a German locale, however, this will return "300100", since ','
is the thousand separator for this locale.
*/
template<
	typename Dest,
	typename Source
>
fcppt::optional::object<
	Dest
>
extract_from_string(
	Source const &_source,
	std::locale const &_locale
		= std::locale()
)
{
	static_assert(
		fcppt::type_traits::is_string<
			Source
		>::value,
		"extract_from_string can only be used on strings"
	);

	typedef
	std::basic_istringstream<
		typename
		Source::value_type,
		typename
		Source::traits_type
	>
	istringstream;

	istringstream iss(
		_source
	);

	iss.imbue(
		_locale
	);

	fcppt::optional::object<
		Dest
	> result{
		fcppt::io::extract<
			Dest
		>(
			iss
		)
	};

	return
		iss.eof()
		?
			std::move(
				result
			)
		:
			fcppt::optional::nothing{}
		;
}

}

#endif
