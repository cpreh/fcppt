//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPL_ASSERTION_FAILED_HPP_INCLUDED
#define FCPPT_IMPL_ASSERTION_FAILED_HPP_INCLUDED

#include <fcppt/lexical_cast.hpp>
#include <fcppt/text.hpp>
#include <fcppt/string.hpp>

inline
fcppt::assertion_failed::assertion_failed(
	fcppt::string const &_file,
	int const _line,
	fcppt::string const &_function,
	fcppt::string const &_condition,
	fcppt::string const &_message)
:
	exception(
		_file+
		FCPPT_TEXT(":")
		+
		lexical_cast<fcppt::string>(
			_line
		)
		+
		FCPPT_TEXT(": ")
		+
		(
			_function.empty() 
			? 
				fcppt::string()
			:
				fcppt::string(
					FCPPT_TEXT("In function \"")
					+
					_function
					+
					FCPPT_TEXT("\": ")
				)
		)
		+
		FCPPT_TEXT("Assertion \"")
		+
		_condition+
		FCPPT_TEXT("\" failed")
		+
		(
			_message.empty() 
			? 
				fcppt::string()
			:
				fcppt::string(
					FCPPT_TEXT(": ")
				)
				+
				_message
		)
	),
	file_(
		_file),
	line_(
		_line),
	function_(
		_function),
	condition_(
		_condition),
	message_(
		_message)
{
}

inline
fcppt::string const &
fcppt::assertion_failed::file() const
{
	return file_;
}

inline
int	
fcppt::assertion_failed::line() const
{
	return line_;
}

inline
fcppt::string const &
fcppt::assertion_failed::function() const
{
	return function_;
}

inline
fcppt::string const &
fcppt::assertion_failed::condition() const
{
	return condition_;
}

inline
fcppt::string const &
fcppt::assertion_failed::message() const
{
	return message_;
}

inline
fcppt::assertion_failed::~assertion_failed() throw()
{
}

#endif
