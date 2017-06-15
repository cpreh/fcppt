//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DYNAMIC_CROSS_FUN_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_CROSS_FUN_HPP_INCLUDED

#include <fcppt/cast/dynamic_cross.hpp>
#include <fcppt/optional/reference.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Function object that uses \link fcppt::cast::dynamic_cross\endlink

\ingroup fcpptcasts
*/
struct dynamic_cross_fun
{
	template<
		typename Dest,
		typename Source
	>
	static
	fcppt::optional::reference<
		Dest
	>
	execute(
		Source &_source
	)
	noexcept
	{
		return
			fcppt::cast::dynamic_cross<
				Dest
			>(
				_source
			);
	}
};

}
}

#endif
