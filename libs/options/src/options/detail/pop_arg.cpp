//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/options/parse_arguments.hpp>
#include <fcppt/options/detail/pop_arg.hpp>
#include <fcppt/options/impl/next_arg.hpp>


fcppt::optional_string
fcppt::options::detail::pop_arg(
	fcppt::reference<
		fcppt::options::parse_arguments
	> const _parse_args
)
{
	fcppt::args_vector &args{
		_parse_args.get().state_.args_
	};

	return
		fcppt::optional::map(
			fcppt::options::impl::next_arg(
				args,
				_parse_args.get().option_names_
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
