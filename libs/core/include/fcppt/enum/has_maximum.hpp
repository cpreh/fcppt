//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_HAS_MAXIMUM_HPP_INCLUDED
#define FCPPT_ENUM_HAS_MAXIMUM_HPP_INCLUDED

#include <fcppt/enum/detail/has_maximum.hpp>

namespace fcppt::enum_
{

/**
\brief Tests if an enum has fcppt_maximum as a member.
\ingroup fcpptenum
*/
template<typename Enum>
using has_maximum = typename fcppt::enum_::detail::has_maximum<Enum>::type;

}

#endif
