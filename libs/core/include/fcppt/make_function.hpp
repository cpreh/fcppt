//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_FUNCTION_HPP_INCLUDED
#define FCPPT_MAKE_FUNCTION_HPP_INCLUDED

#include <fcppt/function_impl.hpp>


namespace fcppt
{

/**
\brief Creates an #fcppt::function.

\ingroup fcpptvarious
*/
template<
	typename Ret,
	typename... Args
>
fcppt::function<
	Ret (
		Args...
	)
>
make_function(
	Ret (
		&_function
	)(
		Args...
	)
)
{
	return
		fcppt::function<
			Ret (
				Args...
			)
		>(
			_function
		);
}

}

#endif
