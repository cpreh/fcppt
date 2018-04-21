//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/at_optional.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/copy_value.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/options/detail/is_flag.hpp>


bool
fcppt::options::detail::is_flag(
	fcppt::string const &_value
)
{
	return
		fcppt::optional::copy_value(
			fcppt::container::at_optional(
				_value,
				0u
			)
		)
		==
		fcppt::optional::make(
			FCPPT_TEXT('-')
		);
}
