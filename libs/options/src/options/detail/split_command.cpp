//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/string.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/option_name_set.hpp>
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
	fcppt::args_vector const &_args,
	fcppt::options::option_name_set const &_option_names
)
{
	return
		fcppt::optional::map(
			fcppt::options::impl::next_arg(
				_args,
				_option_names
			),
			[
				&_args
			](
				fcppt::args_vector::const_iterator const _pos
			)
			{
				return
					std::make_tuple(
						fcppt::args_vector{
							_args.begin(),
							_pos
						},
						*_pos,
						fcppt::args_vector{
							std::next(
								_pos
							),
							_args.end()
						}
					);
			}
		);
}
