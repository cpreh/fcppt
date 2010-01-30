//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/detail/process_assert.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <ostream>

void
fcppt::detail::process_assert(
	string const &file,
	string const &line,
	string const &condition,
	string const &message
)
{
	io::ostringstream ss;

	ss
		<< file
		<< FCPPT_TEXT(':')
		<< line
		<< FCPPT_TEXT(": assertion failed: ")
		<< condition;

	if (!message.empty())
		ss
			<< FCPPT_TEXT(", ")
			<< message;

	throw exception(
		ss.str()
	);
}
