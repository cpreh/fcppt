//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_SUB_COMMAND_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_SUB_COMMAND_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/sub_command_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

template<
	typename Parser
>
inline
fcppt::options::sub_command<
	fcppt::type_traits::remove_cv_ref_t<
		Parser
	>
>
make_sub_command(
	fcppt::string &&_name,
	Parser &&_parser
)
{
	return
		fcppt::options::sub_command<
			fcppt::type_traits::remove_cv_ref_t<
				Parser
			>
		>(
			std::move(
				_name
			),
			std::move(
				_parser
			)
		);
}

}
}

#endif
