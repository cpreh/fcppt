//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/string.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/parse_arguments.hpp>
#include <fcppt/options/detail/split_command.hpp>
#include <fcppt/options/impl/next_arg.hpp>
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
	fcppt::options::parse_arguments const &_parse_args,
	fcppt::string const &_command
)
{
	fcppt::args_vector const &args{
		_parse_args.state_.args_
	};

	return
		fcppt::optional::bind(
			fcppt::options::impl::next_arg(
				args,
				_parse_args.option_names_
			),
			[
				&_command,
				&args
			](
				fcppt::args_vector::const_iterator const _pos
			)
			{
				return
					fcppt::optional::make_if(
						*_pos
						==
						_command,
						[
							_pos,
							&args
						]{
							return
								std::make_pair(
									fcppt::args_vector{
										args.begin(),
										_pos
									},
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
		);
}
