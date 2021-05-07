//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TAG_TYPE_HPP_INCLUDED
#define FCPPT_TAG_TYPE_HPP_INCLUDED

#include <fcppt/detail/tag_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Extracts the type of #fcppt::tag

\ingroup fcpptvarious
*/
template <typename Type>
using tag_type = typename fcppt::detail::tag_type<std::remove_cvref_t<Type>>::type;

}

#endif
