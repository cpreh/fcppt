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
