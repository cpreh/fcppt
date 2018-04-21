//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_CONCRETE_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_CONCRETE_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_arguments_fwd.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/detail/concrete_decl.hpp>
#include <fcppt/options/detail/deref.hpp>
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
	base_type(),
	parser_(
		std::move(
			_parser
		)
	)
{
}

template<
	typename Result,
	typename Parser
>
fcppt::options::detail::concrete<
	Result,
	Parser
>::concrete(
	Parser const &_parser
)
:
	base_type(),
	parser_(
		_parser
	)
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
fcppt::options::result<
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
	fcppt::options::parse_arguments &_state
) const
{
	return
		fcppt::either::map(
			fcppt::options::detail::deref(
				parser_
			).parse(
				_state
			),
			[](
				fcppt::options::result_of<
					Parser
				> &&_result
			)
			{
				return
					fcppt::record::permute<
						result_type
					>(
						std::move(
							_result
						)
					);
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
		fcppt::options::detail::deref(
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
		fcppt::options::detail::deref(
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
		fcppt::options::detail::deref(
			parser_
		).usage();
}

#endif
