//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_UPDATE_ACTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_UPDATE_ACTION_HPP_INCLUDED

#include <fcppt/algorithm/update_action_fwd.hpp>

namespace fcppt
{
namespace algorithm
{
/**
\brief Update action for container iteration

\ingroup fcpptalgorithm
*/
enum class update_action
{
  /**
  \brief Keep the element
  */
  keep,
  /**
  \brief Remove the element
  */
  remove
};

}
}

#endif
