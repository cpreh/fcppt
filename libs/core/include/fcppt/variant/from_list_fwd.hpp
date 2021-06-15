//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_FROM_LIST_FWD_HPP_INCLUDED
#define FCPPT_VARIANT_FROM_LIST_FWD_HPP_INCLUDED

#include <fcppt/metal/as.hpp>
#include <fcppt/metal/list_concept.hpp>
#include <fcppt/variant/object_fwd.hpp>

namespace fcppt::variant
{
/**
\brief Declares a variant using a metal::list.

\ingroup fcpptvariant
*/
template <fcppt::metal::list_concept Types>
using from_list = fcppt::metal::as<fcppt::variant::object, Types>;

}

#endif
