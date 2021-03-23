//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ELEMENT_TAG_TUPLE_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_TAG_TUPLE_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/metal/as_tuple.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace record
{
/**
\brief A metafunction returning the elements of record as a
<code>fcppt::tuple::object</code> of <code>fcppt::tag</code> types.

\ingroup fcpptrecord

\tparam Record Must be an #fcppt::record::object.
*/
template <typename Record>
using element_tag_tuple = fcppt::metal::as_tuple<
    ::metal::transform<::metal::lambda<fcppt::tag>, fcppt::record::element_vector<Record>>>;

}
}

#endif
