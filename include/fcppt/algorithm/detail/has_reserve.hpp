//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_HAS_RESERVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_HAS_RESERVE_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/generate_has_member_function.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

FCPPT_TYPE_TRAITS_GENERATE_HAS_MEMBER_FUNCTION(
	reserve
);

FCPPT_PP_POP_WARNING

}
}
}

#endif
