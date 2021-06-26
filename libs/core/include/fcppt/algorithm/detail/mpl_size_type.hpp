//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_DETAIL_MPL_SIZE_TYPE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_MPL_SIZE_TYPE_HPP_INCLUDED

#include <fcppt/mpl/list/is_object.hpp>
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{
namespace detail
{
template <typename Type, typename Test = void>
struct mpl_size_type
{
  using type = void;
};

template <typename Type>
struct mpl_size_type<Type, std::enable_if_t<fcppt::mpl::list::is_object<Type>::value>>
{
  using type = typename fcppt::mpl::list::size<Type>::value_type;
};

}
}
}

#endif
