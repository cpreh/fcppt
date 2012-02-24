//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_NO_SUCH_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_NO_SUCH_LOCATION_HPP_INCLUDED

#include <fcppt/log/exception.hpp>
#include <fcppt/log/location.hpp>


namespace fcppt
{
namespace log
{

/**
\brief An exception thrown if a location is not found
*/
class no_such_location
:
	public fcppt::log::exception
{
public:
	/**
	\brief Constructs the exception given a location

	Constructs the exception given \a location

	\param location The location that was not found
	*/
	explicit
	no_such_location(
		fcppt::log::location const &location
	);

	/**
	\brief Returns the associated location
	*/
	fcppt::log::location const &
	location() const;

	virtual
	~no_such_location() throw();
private:
	fcppt::log::location location_;
};

}
}

#include <fcppt/log/impl/no_such_location.hpp>

#endif
