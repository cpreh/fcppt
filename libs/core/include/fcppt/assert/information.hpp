//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_INFORMATION_HPP_INCLUDED
#define FCPPT_ASSERT_INFORMATION_HPP_INCLUDED

#include <fcppt/assert/information_fwd.hpp>
#include <fcppt/assert/condition.hpp>
#include <fcppt/assert/file.hpp>
#include <fcppt/assert/function.hpp>
#include <fcppt/assert/line.hpp>
#include <fcppt/assert/message.hpp>

namespace fcppt
{
namespace assert_
{

/**
\brief Represents information gathered at the assertion side

\ingroup fcpptassert

This class is used to construct exceptions thrown by assert macros.
*/
class information
{
public:
	/**
	\brief Constructs the information

	Constructs the information from \a file,
	\a line, \a function, \a condition and \a message.

	\param file The current file

	\param line The line of the current file

	\param function The current function

	\param condition The failed condition

	\param message The message of the assertion
	*/
	information(
		fcppt::assert_::file const &file,
		fcppt::assert_::line line,
		fcppt::assert_::function const &function,
		fcppt::assert_::condition const &condition,
		fcppt::assert_::message const &message
	);

	/**
	\brief Returns the current file
	*/
	fcppt::assert_::file const &
	file() const;

	/**
	\brief Returns the line of the current file
	*/
	fcppt::assert_::line
	line() const;

	/**
	\brief Returns the current function
	*/
	fcppt::assert_::function const &
	function() const;

	/**
	\brief Returns the failed condition
	*/
	fcppt::assert_::condition const &
	condition() const;

	/**
	\brief Returns the message of the assertion
	*/
	fcppt::assert_::message const &
	message() const;
private:
	fcppt::assert_::file file_;

	fcppt::assert_::line line_;

	fcppt::assert_::function function_;

	fcppt::assert_::condition condition_;

	fcppt::assert_::message message_;
};

}
}

#include <fcppt/assert/impl/information.hpp>

#endif
