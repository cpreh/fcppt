//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_ELEMENT_VECTOR_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ELEMENT_VECTOR_HPP_INCLUDED

#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/record/object_fwd.hpp>

namespace fcppt::record::detail
{
template <typename T>
struct element_vector;

template <typename... Types>
struct element_vector<fcppt::record::object<Types...>>
{
  using type = fcppt::mpl::list::object<Types...>;
};

}

#endif
