//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_AS_TUPLE_HPP_INCLUDED
#define FCPPT_METAL_AS_TUPLE_HPP_INCLUDED

#include <fcppt/metal/as.hpp>
#include <fcppt/tuple/object_fwd.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief Turns a metal list into a tuple.

\ingroup fcpptmetal

For <code>List=metal::list<t_1,...,t_n></code>
the result type is <code>fcppt::tuple::object<t_1,...,t_n></code>.

\tparam List Must be a metal::list.
*/
template <typename List>
using as_tuple = fcppt::metal::as<fcppt::tuple::object, List>;

}
}

#endif
