//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_OUT_OF_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_OUT_OF_RANGE_HPP_INCLUDED

#include <fcppt/container/exception.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace container
{

/**
\brief An exception thrown by some containers if an index is out of bounds
\ingroup fcpptcontainer
*/
class out_of_range
:
	public container::exception
{
public:
	out_of_range();
};

}
}

#include <fcppt/container/impl/out_of_range.hpp>

#endif
