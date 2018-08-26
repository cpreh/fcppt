//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_CONCRETE_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_CONCRETE_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/options/detail/concrete_decl.hpp>
#include <fcppt/record/permute.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Result,
	typename Parser
>
fcppt::options::detail::concrete<
	Result,
	Parser
>::concrete(
	Parser &&_parser
)
:
	base_type{},
	parser_{
		std::move(
			_parser
		)
	}
{
}

template<
	typename Result,
	typename Parser
>
fcppt::options::detail::concrete<
	Result,
	Parser
>::~concrete()
{
}

template<
	typename Result,
	typename Parser
>
fcppt::options::parse_result<
	typename
	fcppt::options::detail::concrete<
		Result,
		Parser
	>::result_type
>
fcppt::options::detail::concrete<
	Result,
	Parser
>::parse(
	fcppt::options::state &&_state,
	fcppt::options::parse_context const &_context
) const
{
	return
		fcppt::either::map(
			fcppt::options::deref(
				parser_
			).parse(
				std::move(
					_state
				),
				_context
			),
			[](
				fcppt::options::state_with_value<
					fcppt::options::result_of<
						Parser
					>
				> &&_result
			)
			{
				return
					fcppt::options::state_with_value<
						result_type
					>{
						std::move(
							_result.state_
						),
						fcppt::record::permute<
							result_type
						>(
							std::move(
								_result.value_
							)
						)
					};
			}
		);
}

template<
	typename Result,
	typename Parser
>
fcppt::options::flag_name_set
fcppt::options::detail::concrete<
	Result,
	Parser
>::flag_names() const
{
	return
		fcppt::options::deref(
			parser_
		).flag_names();
}

template<
	typename Result,
	typename Parser
>
fcppt::options::option_name_set
fcppt::options::detail::concrete<
	Result,
	Parser
>::option_names() const
{
	return
		fcppt::options::deref(
			parser_
		).option_names();
}

template<
	typename Result,
	typename Parser
>
fcppt::string
fcppt::options::detail::concrete<
	Result,
	Parser
>::usage() const
{
	return
		fcppt::options::deref(
			parser_
		).usage();
}

#endif
