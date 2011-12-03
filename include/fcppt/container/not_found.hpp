//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_NOT_FOUND_HPP_INCLUDED
#define FCPPT_CONTAINER_NOT_FOUND_HPP_INCLUDED

#include <fcppt/container/exception.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace container
{

/**
\brief FIXME
\ingroup fcpptcontainer
*/
class not_found
:
	public container::exception
{
public:
	explicit not_found(
		fcppt::string const &
	);
};

}
}

#include <fcppt/container/impl/not_found.hpp>

#endif
