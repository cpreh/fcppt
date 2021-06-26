//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_FROM_LIST_FWD_HPP_INCLUDED
#define FCPPT_RECORD_FROM_LIST_FWD_HPP_INCLUDED

#include <fcppt/mpl/list/as.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/record/object_fwd.hpp>

namespace fcppt
{
namespace record
{
/**
\brief Declares a record using an mpl::list.

\ingroup fcpptrecord
*/
template <fcppt::mpl::list::object_concept List>
using from_list = fcppt::mpl::list::as<fcppt::record::object, List>;

}
}

#endif
