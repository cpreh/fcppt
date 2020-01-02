//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/options/parse_context.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/pop_arg.hpp>
#include <fcppt/options/impl/next_arg.hpp>


fcppt::optional_string
fcppt::options::detail::pop_arg(
	fcppt::reference<
		fcppt::options::state
	> const _state,
	fcppt::options::parse_context const &_context
)
{
	fcppt::args_vector &args{
		_state.get().args_
	};

	return
		fcppt::optional::map(
			fcppt::options::impl::next_arg(
				args,
				_context.option_names_
			),
			[
				&args
			](
				fcppt::args_vector::const_iterator const _pos
			)
			->
			fcppt::string
			{
				fcppt::string result{
					*_pos
				};

				args.erase(
					_pos
				);

				return
					result;
			}
		);
}
