//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/prefix.hpp>
#include <fcppt/log/format/prefix_string.hpp>


fcppt::log::format::function
fcppt::log::format::prefix(
	fcppt::log::format::prefix_string const &_prefix
)
{
	return
		fcppt::log::format::function{
			[
				_prefix
			](
				fcppt::string const &_text
			)
			-> fcppt::string
			{
				return
					_prefix.get()
					+
					FCPPT_TEXT(": ")
					+
					_text;
			}
		};
}
