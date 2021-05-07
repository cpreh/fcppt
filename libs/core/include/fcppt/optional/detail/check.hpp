//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_DETAIL_CHECK_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_CHECK_HPP_INCLUDED

#include <fcppt/optional/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace optional
{
namespace detail
{
template <typename Type>
using check = fcppt::optional::is_object<std::remove_cvref_t<Type>>;

}
}
}

#endif
