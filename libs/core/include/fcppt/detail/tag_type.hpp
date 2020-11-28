//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_TAG_TYPE_HPP_INCLUDED
#define FCPPT_DETAIL_TAG_TYPE_HPP_INCLUDED

#include <fcppt/tag_fwd.hpp>

namespace fcppt
{
namespace detail
{
template <typename Type>
struct tag_type;

template <typename Type>
struct tag_type<fcppt::tag<Type>>
{
  using type = Type;
};

}
}

#endif
