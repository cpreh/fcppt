//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/options/parse_arguments.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/is_flag.hpp>
#include <fcppt/options/detail/pop_arg.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


fcppt::optional_string
fcppt::options::detail::pop_arg(
	fcppt::reference<
		fcppt::options::parse_arguments
	> const _args
)
{
	fcppt::options::state &state{
		_args.get().state_
	};

	fcppt::args_vector::const_iterator const end{
		state.args_.end()
	};

	// TODO: This is terrible
	for(
		fcppt::args_vector::iterator cur{
			state.args_.begin()
		};
		cur != end;
	)
	{
		if(
			fcppt::options::detail::is_flag(
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
				_args.get().option_names_.get().count(
					*cur
				)
				>=
				1u
			)
				++cur;

			continue;
		}

		fcppt::string result{
			*cur
		};

		state.args_.erase(
			cur
		);

		return
			fcppt::optional_string{
				std::move(
					result
				)
			};
	}

	return
		fcppt::optional_string{};
}
