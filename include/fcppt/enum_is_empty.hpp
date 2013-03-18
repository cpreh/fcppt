//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_IS_EMPTY_HPP_INCLUDED
#define FCPPT_ENUM_IS_EMPTY_HPP_INCLUDED

#include <fcppt/enum_is_empty_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Tells if an enum is empty

\ingroup fcpptenum

Specialize this to tell if an enum is empty. The default behavior is that it's
not empty.
*/
template<
	typename Enum
>
struct enum_is_empty
:
std::false_type
{
};

FCPPT_PP_POP_WARNING

}

#endif
