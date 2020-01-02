//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_UNIT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_UNIT_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/unit_decl.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/object_impl.hpp>


template<
	typename Label
>
fcppt::options::unit<
	Label
>::unit()
{
}

template<
	typename Label
>
fcppt::options::parse_result<
	typename
	fcppt::options::unit<
		Label
	>::result_type
>
fcppt::options::unit<
	Label
>::parse(
	fcppt::options::state &&_state,
	fcppt::options::parse_context const &
) const
{
	return
		_state.empty()
		?
			fcppt::options::parse_result<
				result_type
			>{
				fcppt::options::state_with_value<
					result_type
				>{
					std::move(
						_state
					),
					result_type{
						Label{} =
							fcppt::unit{}
					}
				}
			}
		:
			fcppt::either::make_failure<
				fcppt::options::state_with_value<
					result_type
				>
			>(
				fcppt::options::parse_error{
					fcppt::options::other_error{
						FCPPT_TEXT("Excess arguments")
					}
				}
			)
		;
}

template<
	typename Label
>
fcppt::options::flag_name_set
fcppt::options::unit<
	Label
>::flag_names() const
{
	return
		fcppt::options::flag_name_set{};
}

template<
	typename Label
>
fcppt::options::option_name_set
fcppt::options::unit<
	Label
>::option_names() const
{
	return
		fcppt::options::option_name_set{};
}

template<
	typename Label
>
fcppt::string
fcppt::options::unit<
	Label
>::usage() const
{
	return
		fcppt::string{};
}

#endif
