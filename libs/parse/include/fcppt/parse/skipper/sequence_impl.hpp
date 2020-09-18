//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_SKIPPER_SEQUENCE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_SEQUENCE_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/skipper/result.hpp>
#include <fcppt/parse/skipper/sequence_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Left,
	typename Right
>
fcppt::parse::skipper::sequence<
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
	typename Ch
>
fcppt::parse::skipper::result<
	Ch
>
fcppt::parse::skipper::sequence<
	Left,
	Right
>::skip(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state
) const
{
	return
		fcppt::either::bind(
			fcppt::parse::deref(
				this->left_
			).skip(
				_state
			),
			[
				&_state,
				this
			](
				fcppt::either::no_error
			)
			{
				return
					fcppt::parse::deref(
						this->right_
					).skip(
						_state
					);
			}
		);
}

#endif
