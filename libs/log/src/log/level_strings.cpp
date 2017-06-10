//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enum_names_array.hpp>
#include <fcppt/enum_names_impl_fwd.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_strings.hpp>


namespace
{

fcppt::enum_names_array<
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

fcppt::enum_names_array<
	fcppt::log::level
> const &
fcppt::enum_names_impl<
	fcppt::log::level
>::get()
{
	return
		strings;
}
