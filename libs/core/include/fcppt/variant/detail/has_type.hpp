//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_DETAIL_HAS_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_HAS_TYPE_HPP_INCLUDED

#include <fcppt/metal/contains.hpp>
#include <fcppt/variant/types_of.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{
template <typename Variant, typename Element>
using has_type = fcppt::metal::contains<fcppt::variant::types_of<Variant>, Element>;

}
}
}

#endif
