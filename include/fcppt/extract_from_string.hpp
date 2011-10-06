//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXTRACT_FROM_STRING_HPP_INCLUDED
#define FCPPT_EXTRACT_FROM_STRING_HPP_INCLUDED

#include <fcppt/default_locale.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <locale>
#include <sstream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	fcppt::type_traits::is_string<
		Source
	>,
	fcppt::optional<
		Dest
	>
>::type
extract_from_string(
	Source const &_source,
	std::locale const &_locale
		= fcppt::default_locale()
)
{
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

	typedef fcppt::optional<
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
