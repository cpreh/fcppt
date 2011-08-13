//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_MAKE_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_MAKE_MESSAGE_HPP_INCLUDED

#include <fcppt/assert/condition.hpp>
#include <fcppt/assert/file.hpp>
#include <fcppt/assert/function.hpp>
#include <fcppt/assert/line.hpp>
#include <fcppt/assert/message.hpp>
#include <fcppt/lexical_cast.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>

namespace fcppt
{
namespace assert_
{

inline
fcppt::string const
make_message(
	assert_::file const &_file,
	assert_::line const _line,
	assert_::function const &_function,
	assert_::condition const &_condition,
	assert_::message const &_message
)
{
	return
		_file.get()
		+
		FCPPT_TEXT(':')
		+
		fcppt::lexical_cast<
			fcppt::string
		>(
			_line
		)
		+
		FCPPT_TEXT(": ")
		+
		(
			_function.get().empty()
			?
				fcppt::string()
			:
				fcppt::string(
					FCPPT_TEXT("In function \"")
					+
					_function.get()
					+
					FCPPT_TEXT("\": ")
				)
		)
		+
		FCPPT_TEXT("Assertion \"")
		+
		_condition.get()
		+
		FCPPT_TEXT("\" failed")
		+
		(
			_message.get().empty()
			?
				fcppt::string()
			:
				fcppt::string(
					FCPPT_TEXT(": ")
				)
				+
				_message>get()
		);
}

}
}

#endif
