//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_HAS_SIZE_RESERVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_HAS_SIZE_RESERVE_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename A,
	typename B,
	typename Test = void
>
struct has_size_reserve
:
std::false_type
{
};

template<
	typename A,
	typename B
>
struct has_size_reserve<
	A,
	B,
	decltype(
		std::declval<
			A
		>().reserve(
			std::declval<
				B
			>().size()
		)
	)
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
