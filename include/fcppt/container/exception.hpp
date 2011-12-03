//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_EXCEPTION_HPP_INCLUDED
#define FCPPT_CONTAINER_EXCEPTION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/exception.hpp>

namespace fcppt
{
namespace container
{
/**
 * \brief An exception thrown by some container functions
 * \ingroup fcpptcontainer
 */
class exception
:
	public fcppt::exception
{
public:
	explicit exception(
		fcppt::string const &
	);
};

}
}

#include <fcppt/container/impl/exception.hpp>

#endif
