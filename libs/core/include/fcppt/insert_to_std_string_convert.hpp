//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INSERT_TO_STD_STRING_CONVERT_HPP_INCLUDED
#define FCPPT_INSERT_TO_STD_STRING_CONVERT_HPP_INCLUDED

#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Convert an arbitrary type to fcppt::string and then to std::string

\ingroup fcpptstring
*/
template<
	typename Type
>
inline
std::string
insert_to_std_string_convert(
	Type const &_value,
	std::locale const &_locale
		= std::locale()
)
{
	return
		fcppt::to_std_string(
			fcppt::insert_to_fcppt_string(
				_value,
				_locale
			)
		);
}

}

#endif
