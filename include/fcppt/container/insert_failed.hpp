//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_INSERT_FAILED_HPP_INCLUDED
#define FCPPT_CONTAINER_INSERT_FAILED_HPP_INCLUDED

#include <fcppt/container/exception.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace container
{

class insert_failed
:
	public container::exception
{
public:
	explicit insert_failed(
		fcppt::string const &
	);
};

}
}

#include <fcppt/container/impl/insert_failed.hpp>

#endif
