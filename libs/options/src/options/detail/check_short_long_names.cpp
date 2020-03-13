//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/detail/check_short_long_names.hpp>


void
fcppt::options::detail::check_short_long_names(
	fcppt::options::optional_short_name const &_optional_short_name,
	fcppt::options::long_name const &_long_name
)
{
	fcppt::optional::maybe_void(
		_optional_short_name,
		[
			&_long_name
		](
			fcppt::options::short_name const &_short_name
		)
		{
			if(
				_short_name.get()
				==
				_long_name.get()
			)
			{
				throw
					fcppt::options::duplicate_names{
						FCPPT_TEXT("Long and short options cannot have the same name: ")
						+
						_short_name.get()
					};
			}
		}
	);
}
