//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_IS_OBJECT_HPP_INCLUDED
#define FCPPT_ENUM_IS_OBJECT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{

/**
\brief Checks if a type is usable with fcppt.enum.
*/
template<typename Enum>
using is_object = std::is_enum<Enum>;
}

#endif
