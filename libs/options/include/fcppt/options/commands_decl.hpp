//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_COMMANDS_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_COMMANDS_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/commands_fwd.hpp>
#include <fcppt/options/flag_name_set_fwd.hpp>
#include <fcppt/options/option_name_set_fwd.hpp>
#include <fcppt/options/options_label.hpp>
#include <fcppt/options/parse_arguments_fwd.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/sub_command_impl.hpp>
#include <fcppt/options/sub_command_label.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/variadic_fwd.hpp>
#include <fcppt/variant/variadic_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

template<
	typename OptionsParser,
	typename... SubCommands
>
class commands
{
public:
	static_assert(
		sizeof...(
			SubCommands
		)
		>=
		1u,
		"You must specify at least one subparser"
	);

	explicit
	commands(
		OptionsParser &&,
		fcppt::options::sub_command<
			SubCommands
		> &&...
	);

	typedef
	fcppt::variant::variadic<
		fcppt::options::result_of<
			SubCommands
		>...
	>
	variant_result;

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			fcppt::options::options_label,
			fcppt::options::result_of<
				OptionsParser
			>
		>,
		fcppt::record::element<
			fcppt::options::sub_command_label,
			variant_result
		>
	>
	result_type;

	fcppt::options::result<
		result_type
	>
	parse(
		fcppt::options::parse_arguments &
	) const;

	fcppt::options::flag_name_set
	flag_names() const;

	fcppt::options::option_name_set
	option_names() const;

	fcppt::string
	usage() const;
private:
	OptionsParser options_parser_;

	std::tuple<
		fcppt::options::sub_command<
			SubCommands
		>...
	>
	sub_commands_;
};

}
}

#endif
