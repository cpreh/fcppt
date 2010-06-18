//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXCEPTION_HPP_INCLUDED
#define FCPPT_EXCEPTION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <exception>

namespace fcppt
{

/**
 * @brief The base class for all exceptions.
 *
 * fcppt::exception is a wrapper around an exception
 * that uses fcppt::string to store the error message.
 * Note that you will have to use fcppt::exception::string
 * to obtain the string. If you use what() nothing useful
 * will be given.
*/
class exception
:
	public std::exception
{
public:
	explicit exception(
		fcppt::string const &
	);

	exception(
		exception const &
	);

	exception &
	operator=(
		exception const &
	);

	fcppt::string const &
	string() const;

	char const *
	what() const throw();

	virtual ~exception() throw();
private:
	fcppt::string s;
};

}

#include <fcppt/impl/exception.hpp>

#endif
