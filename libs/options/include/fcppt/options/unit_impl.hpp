//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_UNIT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_UNIT_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_arguments.hpp>
#include <fcppt/options/unit_decl.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/variadic.hpp>


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
fcppt::options::result<
	typename
	fcppt::options::unit<
		Label
	>::result_type
>
fcppt::options::unit<
	Label
>::parse(
	fcppt::options::parse_arguments &_args
) const
{
	return
		_args.state_.empty()
		?
			fcppt::either::make_success<
				fcppt::options::error
			>(
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
		fcppt::options::flag_name_set{
			fcppt::options::name_set{}
		};
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
		fcppt::options::option_name_set{
			fcppt::options::name_set{}
		};
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
