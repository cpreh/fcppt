//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_TEST_RESERVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_TEST_RESERVE_HPP_INCLUDED

#include <fcppt/algorithm/detail/has_reserve.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Container
>
struct test_reserve
:
fcppt::algorithm::detail::has_reserve<
	Container,
	void
	(Container::*)(
		typename
		Container::size_type
	)
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
