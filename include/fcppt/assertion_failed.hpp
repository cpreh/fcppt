//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERTION_FAILED_HPP_INCLUDED
#define FCPPT_ASSERTION_FAILED_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{

/// May be thrown by FCPPT_ASSERT and FCPPT_ASSERT_MESSAGE
class assertion_failed
:
	public exception
{
public:
	explicit assertion_failed(
		fcppt::string const &file,
		int line,
		fcppt::string const &function,
		fcppt::string const &condition,
		fcppt::string const &message
	);
	
	fcppt::string const &
	file() const;

	int	
	line() const;

	fcppt::string const &
	function() const;

	fcppt::string const &
	condition() const;

	fcppt::string const &
	message() const;

	~assertion_failed() throw();
private:
	fcppt::string file_;
	int line_;
	fcppt::string function_;
	fcppt::string condition_;
	fcppt::string message_;
};

}

#include <fcppt/impl/assertion_failed.hpp>

#endif
