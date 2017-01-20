//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/detail/help_text.hpp>


fcppt::string
fcppt::options::detail::help_text(
	fcppt::options::optional_help_text const &_text
)
{
	return
		fcppt::optional::maybe(
			_text,
			[]{
				return
					fcppt::string{};
			},
			[](
				fcppt::options::help_text const &_help_text
			)
			{
				return
					FCPPT_TEXT(" - ")
					+
					_help_text.get();
			}
		);
}
