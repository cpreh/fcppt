//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_EXCEPTION_HPP_INCLUDED
#define FCPPT_LOG_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>


namespace fcppt
{
namespace log
{

/**
\brief The exception base class for logger exceptions

\ingroup fcpptlog
*/
class exception
:
	public fcppt::exception
{
public:
	/**
	\brief Constructs the exception given an error message

	Constructs the exception give \a message

	\param message The message of the exception
	*/
	explicit
	exception(
		fcppt::string const &message
	);
};

}
}

#include <fcppt/log/impl/exception.hpp>

#endif
