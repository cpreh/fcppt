//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_REFERENCE_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONAL_REFERENCE_TYPE_HPP_INCLUDED

#include <fcppt/optional/object_concept.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace optional
{
/**
\brief The reference type of an optional.

\ingroup fcpptoptional
*/
template <fcppt::optional::object_concept Optional>
using reference_type = decltype(std::declval<Optional>().get_unsafe());

}
}

#endif
