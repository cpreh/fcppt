//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IS_RECURSIVE_HPP_INCLUDED
#define FCPPT_IS_RECURSIVE_HPP_INCLUDED

#include <fcppt/recursive_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Tests if a type is an #fcppt::recursive.

\ingroup fcpptvarious
*/
template <typename Type>
struct is_recursive : std::false_type
{
};

template <typename Type>
struct is_recursive<fcppt::recursive<Type>> : std::true_type
{
};

}

#endif
