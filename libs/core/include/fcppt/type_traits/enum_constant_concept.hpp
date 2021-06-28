//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_TRAITS_ENUM_CONSTANT_CONCEPT_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_ENUM_CONSTANT_CONCEPT_HPP_INCLUDED

#include <fcppt/type_traits/integral_constant_concept.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::type_traits
{
template <typename Type>
concept enum_constant_concept = fcppt::type_traits::integral_constant_concept<Type> &&
    std::is_enum_v<fcppt::type_traits::value_type<Type>>;
}

#endif
