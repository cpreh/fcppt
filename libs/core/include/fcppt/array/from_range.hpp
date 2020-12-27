//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_FROM_RANGE_HPP_INCLUDED
#define FCPPT_ARRAY_FROM_RANGE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/range/size.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Creates an #fcppt::array::object out of a range.

\ingroup fcpptrarray

\tparam Source Must be a random-access range.
*/
template <std::size_t Size, typename Source>
fcppt::optional::object<
    fcppt::array::object<fcppt::type_traits::value_type<fcppt::type_traits::remove_cv_ref_t<Source>>, Size>>
from_range(Source &&_source)
{
  return fcppt::optional::make_if(fcppt::range::size(_source) == Size, [&_source] {
    return fcppt::array::init<fcppt::array::object<
        fcppt::type_traits::value_type<fcppt::type_traits::remove_cv_ref_t<Source>>,
        Size>>(
        [&_source](auto const _index) { return fcppt::move_if_rvalue<Source>(_source[_index]); });
  });
}

}

#endif
