//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SEPARATOR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SEPARATOR_IMPL_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/container/join.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/parse/basic_literal.hpp>
#include <fcppt/parse/construct.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/separator_decl.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/operators/optional.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Inner,
	typename Ch
>
fcppt::parse::separator<
	Inner,
	Ch
>::separator(
	Inner &&_inner,
	Ch const _sep
)
:
	inner_{
		std::move(
			_inner
		)
	},
	sep_{
		_sep
	}
{
}

template<
	typename Inner,
	typename Ch
>
template<
	typename Skipper
>
fcppt::parse::result<
	Ch,
	typename
	fcppt::parse::separator<
		Inner,
		Ch
	>::result_type
>
fcppt::parse::separator<
	Inner,
	Ch
>::parse(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state,
	fcppt::parse::context<
		Skipper
	> const &_context
) const
{
	FCPPT_MAKE_STRONG_TYPEDEF(
		fcppt::parse::result_of<
			Inner
		>,
		first_type
	);

	auto const inner_parser(
		fcppt::parse::construct<
			first_type
		>(
			fcppt::make_cref(
				fcppt::parse::deref(
					this->inner_
				)
			)
		)
		>>
		*(
			fcppt::parse::basic_literal<
				Ch
			>{
				this->sep_
			}
			>>
			fcppt::make_cref(
				fcppt::parse::deref(
					this->inner_
				)
			)
		)
	);

	auto const parser(
		-
		fcppt::make_ref(
			inner_parser
		)
	);

	return
		fcppt::either::map(
			parser.parse(
				_state,
				_context
			),
			[](
				fcppt::parse::result_of<
					decltype(
						parser
					)
				> &&_result
			)
			{
				return
					fcppt::optional::maybe(
						std::move(
							_result
						),
						[]{
							return
								result_type{};
						},
						[](
							fcppt::parse::result_of<
								decltype(
									inner_parser
								)
							> &&_inner_result
						)
						{
							return
								fcppt::container::join(
									fcppt::container::make<
										result_type
									>(
										std::move(
											std::get<
												0
											>(
												_inner_result
											).get()
										)
									),
									std::move(
										std::get<
											1
										>(
											_inner_result
										)
									)
								);
						}
					);
			}
		);
}

#endif
