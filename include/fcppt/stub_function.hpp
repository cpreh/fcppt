//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STUB_FUNCTION_HPP_INCLUDED
#define FCPPT_STUB_FUNCTION_HPP_INCLUDED

#include <fcppt/log/headers.hpp>
#include <fcppt/log/global.hpp>
#include <fcppt/preprocessor/file.hpp>
#include <fcppt/preprocessor/stringize.hpp>
#include <fcppt/text.hpp>
#include <ostream>

#define FCPPT_STUB_FUNCTION \
FCPPT_LOG_WARNING(\
	fcppt::log::global(),\
	fcppt::log::_\
		<< FCPPT_TEXT("stub in ")\
		<< FCPPT_PP_FILE\
		<< FCPPT_TEXT(" at ")\
		<< FCPPT_PP_STRINGIZE(__LINE__)\
	);

#endif
