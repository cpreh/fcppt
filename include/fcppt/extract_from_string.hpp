//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXTRACT_FROM_STRING_HPP_INCLUDED
#define FCPPT_EXTRACT_FROM_STRING_HPP_INCLUDED

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
\brief Lexical cast a string to a different type using a locale
\tparam Dest The destination type, has to have an <code>operator&gt;&gt;</code> defined
\tparam Source A string type (see fcppt::type_traits::is_string)
\param _source The string to extract from
\param _locale The locale to use (defaults to std::locale())


Note that the string has to be consumed completely.
<code>extract_from_string_exn<float>("3.0 4.0")</code> will fail.

Also note that the default locale for this function is the C locale. This was
chosen deliberately to avoid confusion when converting, for example, "300,100"
to int. Using the C locale, this will fail, since the string isn't completely
consumed. Using a German locale, however, this will return "300100", since ','
is the thousand separator for this locale.

\see fcppt::extract_from_string_exn
\see fcppt::insert_to_string
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

	typedef std::basic_istringstream<
		typename Source::value_type,
		typename Source::traits_type
	> istringstream;

	istringstream iss(
		_source
	);

	iss.imbue(
		_locale
	);

	Dest dest;

	typedef fcppt::optional::object<
		Dest
	> dest_opt;

	return
		(
			!(iss >> dest)
			|| !iss.eof()
		)
		?
			dest_opt()
		:
			dest_opt(
				dest
			)
		;
}

}

#endif
