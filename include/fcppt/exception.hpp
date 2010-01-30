//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXCEPTION_HPP_INCLUDED
#define FCPPT_EXCEPTION_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/class_symbol.hpp>
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
class FCPPT_CLASS_SYMBOL exception
:
	public std::exception
{
public:
	FCPPT_SYMBOL explicit exception(
		fcppt::string const &
	);

	FCPPT_SYMBOL exception(
		exception const &
	);

	FCPPT_SYMBOL exception &
	operator=(
		exception const &
	);

	FCPPT_SYMBOL fcppt::string const &
	string() const;

	FCPPT_SYMBOL char const *
	what() const throw();

	FCPPT_SYMBOL virtual ~exception() throw();
private:
	fcppt::string s;
};

}

#endif
