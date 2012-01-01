//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INSERT_TO_FCPPT_STRING_HPP_INCLUDED
#define FCPPT_INSERT_TO_FCPPT_STRING_HPP_INCLUDED

#include <fcppt/insert_to_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

template<
	typename Source
>
fcppt::string const
insert_to_fcppt_string(
	Source const &_source,
	std::locale const &_locale
		= std::locale()
)
{
	return
		fcppt::insert_to_string<
			fcppt::string
		>(
			_source,
			_locale
		);
}

}

#endif
