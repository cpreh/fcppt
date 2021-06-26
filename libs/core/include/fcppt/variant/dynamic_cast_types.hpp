//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_DYNAMIC_CAST_TYPES_HPP_INCLUDED
#define FCPPT_VARIANT_DYNAMIC_CAST_TYPES_HPP_INCLUDED

#include <fcppt/reference.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/object_concept.hpp>

namespace fcppt::variant
{
/**
\brief The variant element types used for #fcppt::variant::dynamic_cast_.

\ingroup fcpptvariant
*/
template <fcppt::mpl::list::object_concept Types>
using dynamic_cast_types = fcppt::mpl::list::map<Types, fcppt::mpl::lambda<fcppt::reference>>;

}

#endif
