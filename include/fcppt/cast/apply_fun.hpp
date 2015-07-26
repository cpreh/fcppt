//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_APPLY_FUN_HPP_INCLUDED
#define FCPPT_CAST_APPLY_FUN_HPP_INCLUDED

#include <fcppt/cast/apply.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Function object that applies a cast function to a result type

\ingroup fcpptcasts
*/
template<
	typename Fun,
	typename Res
>
struct apply_fun
{
	template<
		typename Src
	>
	constexpr
	Res
	operator()(
		Src const &_src
	) const
	{
		return
			fcppt::cast::apply<
				Fun,
				Res
			>(
				_src
			);
	}
};

}
}

#endif
