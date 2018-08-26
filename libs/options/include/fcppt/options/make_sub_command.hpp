//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_SUB_COMMAND_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_SUB_COMMAND_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/sub_command_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Makes a sub command.

\ingroup fcpptoptions
*/
template<
	typename Tag,
	typename Parser
>
inline
fcppt::options::sub_command<
	Tag,
	fcppt::type_traits::remove_cv_ref_t<
		Parser
	>
>
make_sub_command(
	fcppt::string &&_name,
	Parser &&_parser,
	fcppt::options::optional_help_text &&_help_text
)
{
	return
		fcppt::options::sub_command<
			Tag,
			fcppt::type_traits::remove_cv_ref_t<
				Parser
			>
		>(
			std::move(
				_name
			),
			std::forward<
				Parser
			>(
				_parser
			),
			std::move(
				_help_text
			)
		);
}

}
}

#endif
