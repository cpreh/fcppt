//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_ENABLE_IF_VOID_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_ENABLE_IF_VOID_HPP_INCLUDED

#include <fcppt/type_traits/function_result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace signal
{
namespace detail
{

template<
	typename T
>
using
enable_if_void
=
std::enable_if_t<
	std::is_void_v<
		fcppt::type_traits::function_result<
			T
		>
	>
>;

}
}
}

#endif
