//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_IMPL_INFORMATION_HPP_INCLUDED
#define FCPPT_ASSERT_IMPL_INFORMATION_HPP_INCLUDED

#include <fcppt/assert/condition.hpp>
#include <fcppt/assert/file.hpp>
#include <fcppt/assert/function.hpp>
#include <fcppt/assert/line.hpp>
#include <fcppt/assert/message.hpp>

inline
fcppt::assert_::information::information(
	assert_::file const &_file,
	assert_::line const _line,
	assert_::function const &_function,
	assert_::condition const &_condition,
	assert_::message const &_message
)
:
	file_(
		_file
	),
	line_(
		_line
	),
	function_(
		_function
	),
	condition_(
		_condition
	),
	message_(
		_message
	)
{
}

inline
fcppt::assert_::file const &
fcppt::assert_::information::file() const
{
	return file_;
}

inline
fcppt::assert_::line const
fcppt::assert_::information::line() const
{
	return line_;
}

inline
fcppt::assert_::function const &
fcppt::assert_::information::function() const
{
	return function_;
}

inline
fcppt::assert_::condition const &
fcppt::assert_::information::condition() const
{
	return condition_;
}

inline
fcppt::assert_::message const &
fcppt::assert_::information::message() const
{
	return message_;
}

#endif
