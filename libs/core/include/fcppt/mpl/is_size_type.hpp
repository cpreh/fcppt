//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_IS_SIZE_TYPE_HPP_INCLUDED
#define FCPPT_MPL_IS_SIZE_TYPE_HPP_INCLUDED

#include <fcppt/mpl/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
namespace detail
{
template <typename T>
struct is_size_type
{
  using type = std::false_type;
};

template <std::size_t I>
struct is_size_type<fcppt::mpl::size_type<I>>
{
  using type = std::true_type;
};
}

/**
\brief Checks if a type is a size_type.
\ingroup fcpptmpl
<code>T</code> is a size type if and only if it is of the form
<code>fcppt::mpl::size_type<N></code> for some <code>std::size_t N</code>.
*/
template<typename T>
using is_size_type = typename fcppt::mpl::detail::is_size_type<T>::type;
}

#endif
