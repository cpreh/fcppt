//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ENABLE_VARARG_CTOR_HPP_INCLUDED
#define FCPPT_RECORD_ENABLE_VARARG_CTOR_HPP_INCLUDED

#include <fcppt/record/detail/is_element_init.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace record
{
/**
\brief Checks if a parameter pack is suitable for record initialization.

\ingroup fcpptrecord
*/
template <typename... Args>
using enable_vararg_ctor = std::enable_if_t<std::conjunction_v<
    fcppt::record::detail::is_element_init<fcppt::type_traits::remove_cv_ref_t<Args>>...>>;

}
}

#endif
