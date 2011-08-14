//          Copyright Carl Philipp Reh 2009 - 2011.
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

class information
{
public:
	information(
		assert_::file const &,
		assert_::line,
		assert_::function const &,
		assert_::condition const &,
		assert_::message const &
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
private:
	assert_::file file_;

	assert_::line line_;

	assert_::function function_;

	assert_::condition condition_;

	assert_::message message_;
};

}
}

#include <fcppt/assert/impl/information.hpp>

#endif
