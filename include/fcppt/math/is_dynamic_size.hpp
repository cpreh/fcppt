//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_DYNAMIC_SIZE_HPP_INCLUDED
#define FCPPT_MATH_IS_DYNAMIC_SIZE_HPP_INCLUDED

#include <fcppt/math/detail/dynamic_size.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief A metafunction that checks if T specifies a dynamic size
\ingroup fcpptmath
*/
template<
	typename T
>
struct is_dynamic_size
:
std::is_same<
	T,
	fcppt::math::detail::dynamic_size
>
{};

FCPPT_PP_POP_WARNING

}
}

#endif
