//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_FLAG_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_FLAG_IMPL_HPP_INCLUDED

#include <fcppt/const.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/options/flag_decl.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/variadic.hpp>


template<
	typename Label,
	typename Type
>
fcppt::options::flag<
	Label,
	Type
>::flag(
	fcppt::options::optional_short_name const &_short_name,
	fcppt::options::long_name const &_long_name,
	active_value const &_active_value,
	inactive_value const &_inactive_value
)
:
	short_name_{
		_short_name
	},
	long_name_(
		_long_name
	),
	active_value_{
		_active_value
	},
	inactive_value_{
		_inactive_value
	}
{
}

template<
	typename Label,
	typename Type
>
fcppt::options::result<
	typename
	fcppt::options::flag<
		Label,
		Type
	>::result_type
>
fcppt::options::flag<
	Label,
	Type
>::parse(
	fcppt::options::state &_state
) const
{
	return
		fcppt::either::make_success<
			fcppt::options::error
		>(
			result_type{
				Label{} =
					_state.pop_flag(
						fcppt::to_std_string(
							long_name_.get()
						),
						fcppt::options::state::is_short{
							false
						}
					)
					||
					fcppt::optional::maybe(
						short_name_,
						fcppt::const_(
							false
						),
						[
							&_state
						](
							fcppt::options::short_name const &_short_name
						)
						{
							return
								_state.pop_flag(
									fcppt::to_std_string(
										_short_name.get()
									),
									fcppt::options::state::is_short{
										true
									}
								);
						}
					)
					?
						active_value_.get()
					:
						inactive_value_.get()
			}
		);
}

template<
	typename Label,
	typename Type
>
fcppt::options::has_parameter_set
fcppt::options::flag<
	Label,
	Type
>::parameters() const
{
	return
		fcppt::options::has_parameter_set();
}

template<
	typename Label,
	typename Type
>
fcppt::string
fcppt::options::flag<
	Label,
	Type
>::usage() const
{
	return
		FCPPT_TEXT("[ --")
		+
		long_name_.get()
		+
		fcppt::optional::maybe(
			short_name_,
			[]{
				return
					fcppt::string();
			},
			[](
				fcppt::options::short_name const &_short_name
			)
			{
				return
					FCPPT_TEXT(" | -")
					+
					_short_name.get();
			}
		)
		+
		FCPPT_TEXT(" ]");
}

#endif
