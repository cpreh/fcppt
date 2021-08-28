//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_PARTITION_RESULT_FWD_HPP_INCLUDED
#define FCPPT_VARIANT_PARTITION_RESULT_FWD_HPP_INCLUDED

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/as.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/tuple/object_fwd.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/variant/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt::variant
{
/**
\brief The result of #fcppt::variant::partition.
\ingroup fcpptvariant

Partitioning a <code>Container<fcppt::variant::object<T_1,...,T_n>></code>
yields <code>fcppt::tuple::object<std::vector<T_1>,...,std::vector<T_n>></code>.
*/
template <typename Container>
using partition_result = fcppt::mpl::list::as<
    fcppt::tuple::object,
    fcppt::mpl::list::map<
        fcppt::variant::types_of<fcppt::type_traits::value_type<Container>>,
        fcppt::mpl::lambda<std::vector>>>;
}

#endif
