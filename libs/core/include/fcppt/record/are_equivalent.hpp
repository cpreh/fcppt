//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ARE_EQUIVALENT_HPP_INCLUDED
#define FCPPT_RECORD_ARE_EQUIVALENT_HPP_INCLUDED

#include <fcppt/metal/maps_equal.hpp>
#include <fcppt/record/element_map.hpp>

namespace fcppt
{
namespace record
{
/**
\brief Tests if two records have the same element maps.

\ingroup fcpptrecord
*/
template <typename Record1, typename Record2>
using are_equivalent = fcppt::metal::
    maps_equal<fcppt::record::element_map<Record1>, fcppt::record::element_map<Record2>>;

}
}

#endif
