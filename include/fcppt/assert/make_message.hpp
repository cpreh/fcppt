//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_MAKE_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_MAKE_MESSAGE_HPP_INCLUDED

#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/information.hpp>


namespace fcppt
{
namespace assert_
{

/**
\brief Generates a message string from assert information

\ingroup fcpptassert

Generates a message string from the assert information contained in \a _info.

\param _info The assert information

\return The formatted message
*/
inline
fcppt::string const
make_message(
	fcppt::assert_::information const &_info
)
{
	return
		_info.file().get()
		+
		FCPPT_TEXT(':')
		+
		fcppt::insert_to_fcppt_string(
			_info.line().get()
		)
		+
		FCPPT_TEXT(": ")
		+
		(
			_info.function().get().empty()
			?
				fcppt::string()
			:
				fcppt::string(
					FCPPT_TEXT("In function \"")
					+
					_info.function().get()
					+
					FCPPT_TEXT("\": ")
				)
		)
		+
		FCPPT_TEXT("Assertion \"")
		+
		_info.condition().get()
		+
		FCPPT_TEXT("\" failed")
		+
		(
			_info.message().get().empty()
			?
				fcppt::string()
			:
				fcppt::string(
					FCPPT_TEXT(": ")
				)
				+
				_info.message().get()
		);
}

}
}

#endif
