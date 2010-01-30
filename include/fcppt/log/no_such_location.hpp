//          Copyright Carl Philipp Reh 2009 - 2010.
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

class FCPPT_CLASS_SYMBOL no_such_location
:
	public exception
{
public:
	FCPPT_SYMBOL explicit no_such_location(
		log::location const &
	);

	log::location const &
	location() const;
private:
	log::location location_;
};

}
}

#endif
