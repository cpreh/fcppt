//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_UNIT_SWITCH_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_UNIT_SWITCH_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/long_name_fwd.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_short_name_fwd.hpp>
#include <fcppt/options/parse_arguments_fwd.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/unit_switch_decl.hpp>
#include <fcppt/options/detail/long_or_short_name.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Label
>
fcppt::options::unit_switch<
	Label
>::unit_switch(
	fcppt::options::optional_short_name &&_short_name,
	fcppt::options::long_name &&_long_name
)
:
	impl_{
		std::move(
			_short_name
		),
		std::move(
			_long_name
		),
		fcppt::options::optional_help_text{}
	}
{
}

template<
	typename Label
>
fcppt::options::result<
	typename
	fcppt::options::unit_switch<
		Label
	>::result_type
>
fcppt::options::unit_switch<
	Label
>::parse(
	fcppt::options::parse_arguments &_state
) const
{
	return
		fcppt::either::bind(
			impl_.parse(
				_state
			),
			[
				this
			](
				fcppt::options::result_of<
					impl
				> const &_result
			)
			{
				return
					fcppt::record::get<
						Label
					>(
						_result
					)
					?
						fcppt::options::make_success(
							result_type{
								Label{} =
									fcppt::unit{}
							}
						)
					:
						fcppt::either::make_failure<
							result_type
						>(
							fcppt::options::error{
								fcppt::options::missing_error{
									FCPPT_TEXT("Missing flag ")
									+
									fcppt::options::detail::long_or_short_name(
										this->impl_.long_name(),
										this->impl_.short_name()
									)
									+
									FCPPT_TEXT(".")
								}
							}
						)
					;
			}
		);
}

template<
	typename Label
>
fcppt::options::flag_name_set
fcppt::options::unit_switch<
	Label
>::flag_names() const
{
	return
		impl_.flag_names();
}

template<
	typename Label
>
fcppt::options::option_name_set
fcppt::options::unit_switch<
	Label
>::option_names() const
{
	return
		impl_.option_names();
}

template<
	typename Label
>
fcppt::string
fcppt::options::unit_switch<
	Label
>::usage() const
{
	return
		fcppt::options::detail::long_or_short_name(
			impl_.long_name(),
			impl_.short_name()
		);
}

template<
	typename Label
>
fcppt::options::optional_short_name const &
fcppt::options::unit_switch<
	Label
>::short_name() const
{
	return
		impl_.short_name();
}

template<
	typename Label
>
fcppt::options::long_name const &
fcppt::options::unit_switch<
	Label
>::long_name() const
{
	return
		impl_.long_name();
}

#endif
