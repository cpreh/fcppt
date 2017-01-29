//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/join_strings.hpp>
#include <fcppt/algorithm/reverse.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/leftover_error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::options::detail::leftover_error(
	fcppt::options::state const &_state
)
{
	// TODO: Make this less ugly

	fcppt::string result;

	if(
		!_state.leftover_args().empty()
	)
		result
			+=
			FCPPT_TEXT("Too many arguments: ")
			+
			fcppt::algorithm::join_strings(
				fcppt::algorithm::reverse(
					_state.leftover_args()
				),
				fcppt::string{
					FCPPT_TEXT(",")
				}
			);

	auto const get_key_names(
		[](
			auto const &_map
		)
		{
			return
				fcppt::algorithm::map<
					std::vector<
						fcppt::string
					>
				>(
					_map,
					[](
						auto const &_value
					)
					{
						auto const expand_name(
							[](
								fcppt::options::state::name_pair const &_name
							)
							{
								return
									(
										_name.second.get()
										?
											FCPPT_TEXT("-")
										:
											FCPPT_TEXT("--")
									)
									+
									_name.first;
							}
						);

						return
							expand_name(
								_value.first
							);
					}
				);
		}
	);

	if(
		!_state.leftover_flags().empty()
	)
	{
		if(
			!result.empty()
		)
			result += FCPPT_TEXT(" ; ");

		result
			+=
			FCPPT_TEXT("Unknown flags: ")
			+
			fcppt::algorithm::join_strings(
				get_key_names(
					_state.leftover_flags()
				),
				fcppt::string{
					FCPPT_TEXT(',')
				}
			);
	}

	if(
		!_state.leftover_options().empty()
	)
	{
		if(
			!result.empty()
		)
			result += FCPPT_TEXT(" ; ");

		result
			+=
			FCPPT_TEXT("Unknown flags: ")
			+
			fcppt::algorithm::join_strings(
				get_key_names(
					_state.leftover_options()
				),
				fcppt::string{
					FCPPT_TEXT(',')
				}
			);
	}

	return
		result;
}
