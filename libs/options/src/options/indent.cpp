//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/join_strings.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/algorithm/split_string.hpp>
#include <fcppt/options/indentation.hpp>
#include <fcppt/options/indent.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::options::indent(
	fcppt::string &&_value,
	fcppt::options::indentation const _indentation
)
{
	return
		fcppt::algorithm::join_strings(
			fcppt::algorithm::map<
				std::vector<
					fcppt::string
				>
			>(
				fcppt::algorithm::split_string(
					_value,
					FCPPT_TEXT('\n')
				),
				[
					_indentation
				](
					fcppt::string &&_element
				)
				{
					return
						fcppt::string(
							_indentation.get(),
							FCPPT_TEXT('\t')
						)
						+
						std::move(
							_element
						);
				}
			),
			FCPPT_TEXT("\n")
		);
}
