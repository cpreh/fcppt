//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/enum/names_array.hpp>
#include <fcppt/enum/names_impl_fwd.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_strings.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wglobal-constructors)
FCPPT_PP_DISABLE_CLANG_WARNING(-Wexit-time-destructors)

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

FCPPT_PP_POP_WARNING

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
