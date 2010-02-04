//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERTION_FAILED_HPP_INCLUDED
#define FCPPT_ASSERTION_FAILED_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/class_symbol.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
class FCPPT_CLASS_SYMBOL assertion_failed
:
	public exception
{
public:
	FCPPT_SYMBOL assertion_failed(
		fcppt::string const &file,
		int line,
		fcppt::string const &function,
		fcppt::string const &condition,
		fcppt::string const &message);
	
	FCPPT_SYMBOL fcppt::string const &
	file() const;

	FCPPT_SYMBOL int	
	line() const;

	FCPPT_SYMBOL fcppt::string const &
	function() const;

	FCPPT_SYMBOL fcppt::string const &
	condition() const;

	FCPPT_SYMBOL fcppt::string const &
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

#endif
