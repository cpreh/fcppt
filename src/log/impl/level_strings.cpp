//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/log/impl/level_string_array.hpp>
#include <fcppt/log/impl/level_strings.hpp>


namespace
{

fcppt::log::impl::level_string_array const strings{{{
	FCPPT_TEXT("verbose"),
	FCPPT_TEXT("debug"),
	FCPPT_TEXT("info"),
	FCPPT_TEXT("warning"),
	FCPPT_TEXT("error"),
	FCPPT_TEXT("fatal")
}}};

}

fcppt::log::impl::level_string_array const &
fcppt::log::impl::level_strings()
{
	return
		strings;
}
