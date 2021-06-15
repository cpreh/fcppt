//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_OBJECT_CONCEPT_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_CONCEPT_HPP_INCLUDED

#include <fcppt/variant/is_object_v.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::variant
{

/**
\brief Checks if a type is a cv-ref variant.
\ingroup fcpptoptional
*/
template<typename Type>
concept object_concept = fcppt::variant::is_object_v<std::remove_cvref_t<Type>>;

}

#endif
