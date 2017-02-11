//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_CONCRETE_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_CONCRETE_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state_fwd.hpp>
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
	fcppt::options::state &_state
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
fcppt::options::has_parameter_set
fcppt::options::detail::concrete<
	Result,
	Parser
>::parameters() const
{
	return
		fcppt::options::detail::deref(
			parser_
		).parameters();
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
