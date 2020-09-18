//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SEQUENCE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SEQUENCE_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/sequence_decl.hpp>
#include <fcppt/parse/detail/sequence_result.hpp>
#include <fcppt/parse/skipper/run.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Left,
	typename Right
>
fcppt::parse::sequence<
	Left,
	Right
>::sequence(
	Left &&_left,
	Right &&_right
)
:
	left_{
		std::move(
			_left
		)
	},
	right_{
		std::move(
			_right
		)
	}
{
}

template<
	typename Left,
	typename Right
>
template<
	typename Ch,
	typename Skipper
>
fcppt::parse::result<
	Ch,
	typename
	fcppt::parse::sequence<
		Left,
		Right
	>::result_type
>
fcppt::parse::sequence<
	Left,
	Right
>::parse(
	fcppt::reference<
		fcppt::parse::basic_stream<
			Ch
		>
	> const _state,
	Skipper const &_skipper
) const
{
	return
		fcppt::either::bind(
			fcppt::parse::deref(
				this->left_
			).parse(
				_state,
				_skipper
			),
			[
				&_state,
				&_skipper,
				this
			](
				fcppt::parse::result_of<
					Left
				> &&_left_result
			)
			{
				return
					fcppt::either::bind(
						fcppt::parse::skipper::run(
							_skipper,
							_state
						),
						[
							&_left_result,
							_state,
							&_skipper,
							this
						](
							fcppt::unit const &
						)
						{
							return
								fcppt::either::map(
									fcppt::parse::deref(
										this->right_
									).parse(
										_state,
										_skipper
									),
									[
										&_left_result
									](
										fcppt::parse::result_of<
											Right
										> &&_right_result
									)
									{
										return
											fcppt::parse::detail::sequence_result(
												std::move(
													_left_result
												),
												std::move(
													_right_result
												)
											);
									}
								);
						}
					);
			}
		);
}

#endif
