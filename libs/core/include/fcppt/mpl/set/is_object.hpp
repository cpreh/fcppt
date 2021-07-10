//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_IS_OBJECT_HPP_INCLUDED
#define FCPPT_MPL_SET_IS_OBJECT_HPP_INCLUDED

#include <fcppt/mpl/set/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::set
{
namespace detail
{
template <typename T>
struct is_object
{
  using type = std::false_type;
};

template <typename... T>
struct is_object<fcppt::mpl::set::object<T...>>
{
  using type = std::true_type;
};
}
/**
\brief Checks if a type is a set.
\ingroup fcpptmpl

<code>T</code> is a set if an only if it is of the form
<code>fcppt::mpl::set::object<T_1, ..., T_n></code> for some types <code>T_1, ..., T_n</code>.
*/
template<typename T>
using is_object = typename fcppt::mpl::set::detail::is_object<T>::type;
}

#endif
