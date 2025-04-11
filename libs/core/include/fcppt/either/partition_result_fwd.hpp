//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_PARTITION_RESULT_FWD_HPP_INCLUDED
#define FCPPT_EITHER_PARTITION_RESULT_FWD_HPP_INCLUDED

#include <fcppt/either/variant_type.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/variant/partition_result_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
/**
\brief The result of #fcppt::either::partition.
\ingroup fcppteither

Partitioning a <code>Container<fcppt::either::object<F,S>></code>
yields <code>fcppt::tuple::object<std::vector`<F`>,std::vector`<S`>></code>.
*/
template <typename Container>
using partition_result = fcppt::variant::partition_result<
    std::vector<fcppt::either::variant_type<fcppt::type_traits::value_type<Container>>>>;
}

#endif
