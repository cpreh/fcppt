//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_EXCEPTION_HPP_INCLUDED
#define FCPPT_ASSERT_EXCEPTION_HPP_INCLUDED

#include <fcppt/assert/condition.hpp>
#include <fcppt/assert/file.hpp>
#include <fcppt/assert/function.hpp>
#include <fcppt/assert/line.hpp>
#include <fcppt/assert/message.hpp>
#include <fcppt/exception.hpp>

namespace fcppt
{
namespace assert_
{

class exception
:
	public fcppt::exception
{
public:
	explicit exception(
		assert_::file,
		assert_::line,
		assert_::function,
		assert_::condition,
		assert_::message
	);

	assert_::file const &
	file() const;

	assert_::line const
	line() const;

	assert_::function const &
	function() const;

	assert_::condition const &
	condition() const;

	assert_::message const &
	message() const;

	~exception() throw();
private:
	assert_::file file_;

	assert_::line line_;

	assert_::function function_;

	assert_::condition condition_;

	assert_::message message_;
};

}
}

#include <fcppt/assert/impl/exception.hpp>

#endif
