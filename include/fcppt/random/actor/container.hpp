//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_ACTOR_CONTAINER_HPP_INCLUDED
#define FCPPT_RANDOM_ACTOR_CONTAINER_HPP_INCLUDED

#include <fcppt/random/actor/element.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace random
{
namespace actor
{

/// The element vector
typedef std::vector<
	actor::element
> container;

}
}
}

#endif
