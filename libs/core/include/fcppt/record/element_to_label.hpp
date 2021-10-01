//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ELEMENT_TO_LABEL_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_TO_LABEL_HPP_INCLUDED

#include <fcppt/record/detail/element_to_label.hpp>

namespace fcppt::record
{
/**
\brief Extracts the type of an #fcppt::record::element.

\ingroup fcpptrecord

\tparam Element Must be an #fcppt::record::element.
*/
template <typename Element>
using element_to_label = typename fcppt::record::detail::element_to_label<Element>::type;

}

#endif
