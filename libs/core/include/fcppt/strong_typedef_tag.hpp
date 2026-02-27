//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STRONG_TYPEDEF_TAG_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_TAG_HPP_INCLUDED

#include <fcppt/detail/strong_typedef_tag.hpp>

namespace fcppt
{
/**
\brief The tag type of a strong typedef.

\ingroup fcpptstrongtypedef

\tparam StrongTypedef Must be an #fcppt::strong_typedef.
*/
template <typename StrongTypedef>
using strong_typedef_tag = fcppt::detail::strong_typedef_tag<StrongTypedef>::type;

}

#endif
