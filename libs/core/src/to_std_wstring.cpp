//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/public_config.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/to_std_wstring.hpp>
#if defined(FCPPT_NARROW_STRING)
#include <fcppt/string_conv_locale.hpp>
#include <fcppt/to_std_wstring_locale.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


std::wstring
fcppt::to_std_wstring(
	fcppt::string_view const &_input
)
{
	return
#if defined(FCPPT_NARROW_STRING)
		fcppt::to_std_wstring_locale(
			_input,
			fcppt::string_conv_locale()
		)
#else
		std::wstring{
			_input
		}
#endif
		;
}
