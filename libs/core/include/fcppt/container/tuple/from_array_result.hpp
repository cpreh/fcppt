//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TUPLE_FROM_ARRAY_RESULT_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_FROM_ARRAY_RESULT_HPP_INCLUDED

#include <fcppt/container/array/size.hpp>
#include <fcppt/metal/as_tuple.hpp>
#include <fcppt/metal/to_number.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace tuple
{
/**
\brief Result of #fcppt::container::tuple::from_array

\ingroup fcpptcontainertuple

\tparam Array Must be a std::array.
*/
template <typename Array>
using from_array_result = fcppt::metal::as_tuple<::metal::repeat<
    fcppt::type_traits::value_type<fcppt::type_traits::remove_cv_ref_t<Array>>,
    fcppt::metal::to_number<
        fcppt::container::array::size<fcppt::type_traits::remove_cv_ref_t<Array>>>>>;

}
}
}

#endif
