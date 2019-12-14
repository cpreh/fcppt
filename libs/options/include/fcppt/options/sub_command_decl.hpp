//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SUB_COMMAND_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_SUB_COMMAND_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/sub_command_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/object_fwd.hpp>


namespace fcppt
{
namespace options
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

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

	typedef
	Parser
	parser_type;

	sub_command(
		fcppt::string &&,
		Parser &&,
		fcppt::options::optional_help_text &&
	);

	fcppt::string const &
	name() const;

	Parser const &
	parser() const;

	fcppt::options::optional_help_text const &
	help_text() const;

	typedef
	fcppt::record::object<
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

FCPPT_PP_POP_WARNING

}
}

#endif
