//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SUB_COMMAND_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_SUB_COMMAND_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/sub_command_fwd.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/variadic_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A sub command consists of a command name and a parser.

\ingroup fcpptoptions
*/
template<
	typename Tag,
	typename Parser
>
class sub_command
{
public:
	typedef
	Tag
	tag;

	sub_command(
		fcppt::string &&,
		Parser &&,
		fcppt::options::optional_help_text &&
	);

	sub_command(
		sub_command const &
	);

	sub_command(
		sub_command &&
	);

	sub_command &
	operator=(
		sub_command const &
	);

	sub_command &
	operator=(
		sub_command &&
	);

	~sub_command();

	fcppt::string const &
	name() const;

	Parser const &
	parser() const;

	fcppt::options::optional_help_text const &
	help_text() const;

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			Tag,
			fcppt::options::result_of<
				Parser
			>
		>
	>
	result_type;
private:
	fcppt::string name_;

	Parser parser_;

	fcppt::options::optional_help_text help_text_;
};

}
}

#endif
