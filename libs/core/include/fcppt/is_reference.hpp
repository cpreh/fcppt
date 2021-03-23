//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IS_REFERENCE_HPP_INCLUDED
#define FCPPT_IS_REFERENCE_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Tests if a type is an #fcppt::reference.

\ingroup fcpptref
*/
template <typename Type>
struct is_reference : std::false_type
{
};

template <typename Type>
struct is_reference<fcppt::reference<Type>> : std::true_type
{
};

}

#endif
