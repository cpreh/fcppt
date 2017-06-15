//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/enum/names_array.hpp>
#include <fcppt/enum/names_impl_fwd.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_strings.hpp>


namespace
{

fcppt::enum_::names_array<
	fcppt::log::level
> const strings{{{
	FCPPT_TEXT("verbose"),
	FCPPT_TEXT("debug"),
	FCPPT_TEXT("info"),
	FCPPT_TEXT("warning"),
	FCPPT_TEXT("error"),
	FCPPT_TEXT("fatal")
}}};

}

fcppt::enum_::names_array<
	fcppt::log::level
> const &
fcppt::enum_::names_impl<
	fcppt::log::level
>::get()
{
	return
		strings;
}
