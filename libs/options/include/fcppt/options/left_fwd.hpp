//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_LEFT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_LEFT_FWD_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/options/detail/left_tag.hpp>

namespace fcppt::options
{
/**
\brief The left result type of a sum parser.

\ingroup fcpptoptions
*/
template <typename Type>
using left = fcppt::strong_typedef<Type, fcppt::options::detail::left_tag>;

}

#endif
