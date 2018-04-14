//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/options/name_set.hpp>
#include <fcppt/options/detail/duplicate_names_text.hpp>


fcppt::string
fcppt::options::detail::duplicate_names_text(
	fcppt::options::name_set const &_names
)
{
	return
		FCPPT_TEXT("A parser with duplicate names was constructed: ")
		+
		fcppt::insert_to_fcppt_string(
			fcppt::container::output(
				_names
			)
		);
}
