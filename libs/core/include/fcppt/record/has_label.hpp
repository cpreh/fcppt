//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_HAS_LABEL_HPP_INCLUDED
#define FCPPT_RECORD_HAS_LABEL_HPP_INCLUDED

#include <fcppt/metal/set/contains.hpp>
#include <fcppt/record/label_set.hpp>

namespace fcppt
{
namespace record
{
/**
\brief Tests if a record has an #fcppt::record::label.

\ingroup fcpptrecord
*/
template <typename Record, typename Label>
using has_label = fcppt::metal::set::contains<fcppt::record::label_set<Record>, Label>;

}
}

#endif
