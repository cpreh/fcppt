//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/string.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/parse_arguments.hpp>
#include <fcppt/options/detail/split_command.hpp>
#include <fcppt/options/impl/next_arg.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <tuple>
#include <fcppt/config/external_end.hpp>


fcppt::optional::object<
	std::tuple<
		fcppt::args_vector,
		fcppt::string,
		fcppt::args_vector
	>
>
fcppt::options::detail::split_command(
	fcppt::options::parse_arguments const &_parse_args
)
{
	fcppt::args_vector const &args{
		_parse_args.state_.args_
	};

	return
		fcppt::optional::map(
			fcppt::options::impl::next_arg(
				args,
				_parse_args.option_names_
			),
			[
				&args
			](
				fcppt::args_vector::const_iterator const _pos
			)
			{
				return
					std::make_tuple(
						fcppt::args_vector{
							args.begin(),
							_pos
						},
						*_pos,
						fcppt::args_vector{
							std::next(
								_pos
							),
							args.end()
						}
					);
			}
		);
}
