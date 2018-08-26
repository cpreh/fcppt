//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/detail/long_or_short_name.hpp>


fcppt::string
fcppt::options::detail::long_or_short_name(
	fcppt::options::long_name const &_long_name,
	fcppt::options::optional_short_name const &_opt_short_name
)
{
	return
		FCPPT_TEXT("--")
		+
		_long_name.get()
		+
		fcppt::optional::maybe(
			_opt_short_name,
			[]{
				return
					fcppt::string();
			},
			[](
				fcppt::options::short_name const &_short_name
			)
			{
				return
					FCPPT_TEXT("|-")
					+
					_short_name.get();
			}
		);
}
