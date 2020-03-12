//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXTRACT_FROM_STRING_LOCALE_HPP_INCLUDED
#define FCPPT_EXTRACT_FROM_STRING_LOCALE_HPP_INCLUDED

#include <fcppt/io/extract.hpp>
#include <fcppt/optional/nothing.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <sstream>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Convert a string to a different type using a locale.

\ingroup fcpptstring

\tparam Dest The destination type, has to have an <code>operator>></code> defined. Must
have either a default constructor or must be constructible from #fcppt::no_init.

\tparam Source A string type (see #fcppt::type_traits::is_string)

\note The string has to be consumed completely.
*/
template<
	typename Dest,
	typename Source
>
fcppt::optional::object<
	Dest
>
extract_from_string_locale(
	Source const &_source,
	std::locale const &_locale
)
{
	static_assert(
		fcppt::type_traits::is_string<
			Source
		>::value,
		"extract_from_string can only be used on strings"
	);

	using
	istringstream
	=
	std::basic_istringstream<
		fcppt::type_traits::value_type<
			Source
		>,
		typename
		Source::traits_type
	>;

	istringstream iss{
		_source
	};

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
