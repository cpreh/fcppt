//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONCEPTS_STRING_HPP_INCLUDED
#define FCPPT_CONCEPTS_STRING_HPP_INCLUDED

#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::concepts
{
/**
\brief Checks if a type is a cv-ref std::basic_string.
\ingroup fcpptconcepts
*/
template<typename Type>
concept string = fcppt::type_traits::is_string<std::remove_cvref_t<Type>>::value;

}

#endif
