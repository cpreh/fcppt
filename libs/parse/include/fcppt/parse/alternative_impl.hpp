//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_ALTERNATIVE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_ALTERNATIVE_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/parse/alternative_decl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/set_position.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Left,
	typename Right
>
fcppt::parse::alternative<
	Left,
	Right
>::alternative(
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
	typename
	fcppt::parse::alternative<
		Left,
		Right
	>::result_type
>
fcppt::parse::alternative<
	Left,
	Right
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
	fcppt::parse::position<
		Ch
	> const old_pos{
		fcppt::parse::get_position(
			_state
		)
	};

	return
		fcppt::optional::maybe(
			fcppt::parse::deref(
				this->left_
			).parse(
				_state,
				_context
			),
			[
				old_pos,
				&_state,
				&_context,
				this
			]{
				fcppt::parse::set_position(
					_state,
					old_pos
				);

				return
					fcppt::optional::bind(
						fcppt::parse::deref(
							this->right_
						).parse(
							_state,
							_context
						),
						[](
							fcppt::parse::result_of<
								Right
							> &&_right_result
						)
						{
							return
								fcppt::optional::make(
									result_type{
										std::move(
											_right_result
										)
									}
								);
						}
					);
			},
			[
			](
				fcppt::parse::result_of<
					Left
				> &&_left_result
			)
			{
				return
					fcppt::optional::make(
						result_type{
							std::move(
								_left_result
							)
						}
					);
			}
		);
}

#endif
