//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_SWITCH_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_SWITCH_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/long_name_fwd.hpp>
#include <fcppt/options/optional_help_text_fwd.hpp>
#include <fcppt/options/optional_short_name_fwd.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/switch_decl.hpp>


template<
	typename Label
>
fcppt::options::switch_<
	Label
>::switch_(
	fcppt::options::optional_short_name const &_short_name,
	fcppt::options::long_name const &_long_name,
	fcppt::options::optional_help_text const &_help_text
)
:
	impl_{
		_short_name,
		_long_name,
		typename
		impl::active_value{
			true
		},
		typename
		impl::inactive_value{
			false
		},
		_help_text
	}
{
}

template<
	typename Label
>
fcppt::options::result<
	typename
	fcppt::options::switch_<
		Label
	>::result_type
>
fcppt::options::switch_<
	Label
>::parse(
	fcppt::options::state &_state
) const
{
	return
		impl_.parse(
			_state
		);
}

template<
	typename Label
>
fcppt::options::has_parameter_set
fcppt::options::switch_<
	Label
>::parameters() const
{
	return
		impl_.parameters();
}

template<
	typename Label
>
fcppt::string
fcppt::options::switch_<
	Label
>::usage() const
{
	return
		impl_.usage();
}

template<
	typename Label
>
fcppt::options::optional_short_name const &
fcppt::options::switch_<
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
fcppt::options::switch_<
	Label
>::long_name() const
{
	return
		impl_.long_name();
}

#endif
