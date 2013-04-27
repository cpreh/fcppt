//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_ARRAY_SIZE_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_ARRAY_SIZE_HPP_INCLUDED

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
namespace container
{
namespace detail
{

template<
	typename Type
>
struct array_size;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	std::size_t N
>
struct array_size<
	std::array<
		T,
		N
	>
>
:
std::integral_constant<
	std::size_t,
	N
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
