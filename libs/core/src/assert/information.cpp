//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assert/condition.hpp>
#include <fcppt/assert/file.hpp>
#include <fcppt/assert/function.hpp>
#include <fcppt/assert/information.hpp>
#include <fcppt/assert/line.hpp>
#include <fcppt/assert/message.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::assert_::information::information(
	fcppt::assert_::file &&_file,
	fcppt::assert_::line const _line,
	fcppt::assert_::function &&_function,
	fcppt::assert_::condition &&_condition,
	fcppt::assert_::message &&_message
)
:
	file_(
		std::move(
			_file
		)
	),
	line_(
		_line
	),
	function_(
		std::move(
			_function
		)
	),
	condition_(
		std::move(
			_condition
		)
	),
	message_(
		std::move(
			_message
		)
	)
{
}

fcppt::assert_::file const &
fcppt::assert_::information::file() const
{
	return
		file_;
}

fcppt::assert_::line
fcppt::assert_::information::line() const
{
	return
		line_;
}

fcppt::assert_::function const &
fcppt::assert_::information::function() const
{
	return
		function_;
}

fcppt::assert_::condition const &
fcppt::assert_::information::condition() const
{
	return
		condition_;
}

fcppt::assert_::message const &
fcppt::assert_::information::message() const
{
	return
		message_;
}
