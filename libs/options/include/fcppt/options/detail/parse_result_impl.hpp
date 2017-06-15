//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_PARSE_RESULT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_PARSE_RESULT_IMPL_HPP_INCLUDED

#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/parse_result_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Result
>
fcppt::options::detail::parse_result<
	Result
>::parse_result(
	Result &&_value,
	fcppt::options::state &&_state
)
:
	value_{
		std::move(
			_value
		)
	},
	state_{
		std::move(
			_state
		)
	}
{
}

template<
	typename Result
>
Result const &
fcppt::options::detail::parse_result<
	Result
>::value() const
{
	return
		value_;
}

template<
	typename Result
>
fcppt::options::state &
fcppt::options::detail::parse_result<
	Result
>::remaining_state()
{
	return
		state_;
}

#endif
