//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IS_STRONG_TYPEDEF_HPP_INCLUDED
#define FCPPT_IS_STRONG_TYPEDEF_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Tests if a type is an #fcppt::strong_typedef.

\ingroup fcpptstrongtypedef
*/
template <typename T>
struct is_strong_typedef : std::false_type
{
};

template <typename Type, typename Tag>
struct is_strong_typedef<fcppt::strong_typedef<Type, Tag>> : std::true_type
{
};

}

#endif
