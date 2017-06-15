//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_STATIC_CAST_FUN_HPP_INCLUDED
#define FCPPT_CAST_STATIC_CAST_FUN_HPP_INCLUDED


namespace fcppt
{
namespace cast
{

/**
\brief Function object that does a static_cast

\ingroup fcpptcasts
*/
struct static_cast_fun
{
	template<
		typename Dest,
		typename Source
	>
	static
	constexpr
	Dest
	execute(
		Source const &_source
	)
	noexcept
	{
		return
			static_cast<
				Dest
			>(
				_source
			);
	}
};

}
}

#endif
