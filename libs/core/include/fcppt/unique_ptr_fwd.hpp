//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_UNIQUE_PTR_FWD_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_FWD_HPP_INCLUDED

#include <fcppt/default_deleter.hpp>

namespace fcppt
{
template <typename Type, typename Deleter = fcppt::default_deleter>
class unique_ptr; // IWYU pragma: export

}

#endif
