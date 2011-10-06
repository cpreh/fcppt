//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INSERT_TO_STD_WSTRING_HPP_INCLUDED
#define FCPPT_INSERT_TO_STD_WSTRING_HPP_INCLUDED

#include <fcppt/default_locale.hpp>
#include <fcppt/insert_to_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

template<
	typename Source
>
std::wstring const
insert_to_std_wstring(
	Source const &_source,
	std::locale const &_locale
		= fcppt::default_locale()
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
