//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_std_string.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/to_std_string_locale.hpp>
#include <fcppt/public_config.hpp>
#if !defined(FCPPT_NARROW_STRING)
#include <fcppt/narrow.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


fcppt::optional_std_string
fcppt::to_std_string_locale(
	fcppt::string_view const &_input,
	std::locale const &
#if !defined(FCPPT_NARROW_STRING)
		_locale
#endif
)
{
#if !defined(FCPPT_NARROW_STRING)
	return
		fcppt::narrow(
			_input,
			_locale
		);
#else
	return
		fcppt::optional_std_string{
			std::string{
				_input
			}
		};
#endif
}
