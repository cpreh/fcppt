//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_IS_VARARG_CTOR_HPP_INCLUDED
#define FCPPT_RECORD_IS_VARARG_CTOR_HPP_INCLUDED

#include <fcppt/record/detail/is_element_init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::record
{
/**
\brief Checks if a parameter pack is suitable for record initialization.

\ingroup fcpptrecord
*/
template <typename... Args>
using is_vararg_ctor =
    std::conjunction<fcppt::record::detail::is_element_init<std::remove_cvref_t<Args>>...>;
}

#endif
