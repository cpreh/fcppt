//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_FROM_ARRAY_RESULT_HPP_INCLUDED
#define FCPPT_TUPLE_FROM_ARRAY_RESULT_HPP_INCLUDED

#include <fcppt/array/is_object.hpp>
#include <fcppt/array/size.hpp>
#include <fcppt/mpl/list/as_tuple.hpp>
#include <fcppt/mpl/list/repeat.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Result of #fcppt::tuple::from_array.

\ingroup fcppttuple
*/
template <typename Array, typename = std::enable_if_t<fcppt::array::is_object<Array>::value>>
using from_array_result = fcppt::mpl::list::as_tuple<
    fcppt::mpl::list::repeat<fcppt::type_traits::value_type<Array>, fcppt::array::size<Array>>>;
}

#endif
