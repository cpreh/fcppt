//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_IS_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T
>
struct is_static_storage
:
std::false_type
{
};

template<
	typename T,
	std::size_t N
>
struct is_static_storage<
	std::array<
		T,
		N
	>
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
