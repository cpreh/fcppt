//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_DETAIL_FUNCTION_ARGS_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_FUNCTION_ARGS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{
namespace detail
{

template<
	typename Function
>
struct function_args;

template<
	typename Ret,
	typename... Args
>
struct function_args<
	Ret (
		Args...
	)
>
{
	typedef
	::metal::list<
		Args...
	>
	type;
};

}
}
}

#endif
