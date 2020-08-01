//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_CHAR_SET_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_SET_IMPL_HPP_INCLUDED

#include <fcppt/output_to_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/contains.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_char_impl.hpp>
#include <fcppt/parse/basic_char_set_decl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/detail/expected.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Ch
>
fcppt::parse::basic_char_set<
	Ch
>::basic_char_set(
	std::initializer_list<
		Ch
	> const &_inits
)
:
	basic_char_set(
		char_set_type{
			_inits
		}
	)
{
}

template<
	typename Ch
>
fcppt::parse::basic_char_set<
	Ch
>::basic_char_set(
	char_set_type &&_chars
)
:
	chars_{
		std::move(
			_chars
		)
	}
{
}

template<
	typename Ch
>
template<
	typename Skipper
>
fcppt::parse::result<
	Ch,
	typename
	fcppt::parse::basic_char_set<
		Ch
	>::result_type
>
fcppt::parse::basic_char_set<
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
	fcppt::parse::basic_char<
		Ch
	> const parser{};

	return
		fcppt::either::bind(
			parser.parse(
				_state,
				_context
			),
			[
				_state,
				this
			](
				Ch const _ch
			)
			{
				return
					fcppt::container::contains(
						this->chars_,
						_ch
					)
					?
						fcppt::parse::make_success<
							Ch
						>(
							_ch
						)
					:
						fcppt::either::make_failure<
							result_type
						>(
							fcppt::parse::detail::expected(
								_state.get().stream().get_position(),
								fcppt::output_to_string<
									std::basic_string<
										Ch
									>
								>(
									fcppt::container::output(
										this->chars_
									)
								),
								_ch
							)
						)
					;
			}
		);
}

template<
	typename Ch
>
typename
fcppt::parse::basic_char_set<
	Ch
>::char_set_type const &
fcppt::parse::basic_char_set<
	Ch
>::chars() const
{
	return
		this->chars_;
}

#endif
