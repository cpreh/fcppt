//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_EXCEPTION_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_EXCEPTION_HPP_INCLUDED

#include <fcppt/container/exception.hpp>
#include <fcppt/string.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

class exception
:
	public fcppt::container::exception
{
public:
	explicit
	exception(
		fcppt::string const &
	);
};

}
}
}

#include <fcppt/container/grid/impl/exception.hpp>

#endif
