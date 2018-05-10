//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/string.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/parse_arguments.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/split_command.hpp>
#include <fcppt/options/impl/is_flag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::optional::object<
	std::pair<
		fcppt::args_vector,
		fcppt::args_vector
	>
>
fcppt::options::detail::split_command(
	fcppt::options::parse_arguments const &_args,
	fcppt::string const &_command
)
{
	typedef
	fcppt::optional::object<
		std::pair<
			fcppt::args_vector,
			fcppt::args_vector
		>
	>
	result_type;

	// TODO: Refactor this together with pop_arg

	fcppt::options::state const &state{
		_args.state_
	};

	fcppt::args_vector::const_iterator const end{
		state.args_.end()
	};

	// TODO: This is terrible
	for(
		fcppt::args_vector::const_iterator cur{
			state.args_.begin()
		};
		cur != end;
	)
	{
		if(
			fcppt::options::impl::is_flag(
				*cur
			)
		)
		{
			++cur;

			if(
				cur
				!=
				end
				&&
				_args.option_names_.get().count(
					*cur
				)
				>=
				1u
			)
				++cur;

			continue;
		}

		if(
			*cur
			==
			_command
		)
			return
				result_type{
					std::make_pair(
						fcppt::args_vector{
							state.args_.begin(),
							cur
						},
						fcppt::args_vector{
							std::next(
								cur
							),
							state.args_.end()
						}
					)
				};

		++cur;
	}

	return
		result_type{};
}
