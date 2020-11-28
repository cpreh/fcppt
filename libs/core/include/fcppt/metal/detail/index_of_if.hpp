//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_DETAIL_INDEX_OF_IF_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_INDEX_OF_IF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace metal
{
namespace detail
{
template <typename List, typename Pred>
struct index_of_if
{
  static_assert(::metal::any_of<List, Pred>::value);

  using type = ::metal::find_if<List, Pred>;
};

}
}
}

#endif
