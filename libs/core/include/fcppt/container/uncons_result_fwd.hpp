//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_UNCONS_RESULT_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_UNCONS_RESULT_FWD_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/iterator/range_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/tuple/object_fwd.hpp>

namespace fcppt::container
{
template <typename Container>
using uncons_result = fcppt::optional::object<fcppt::tuple::object<
    fcppt::reference<fcppt::container::to_value_type<Container>>,
    fcppt::iterator::range<fcppt::container::to_iterator_type<Container>>>>;
}

#endif
