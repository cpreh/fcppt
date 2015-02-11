//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_APPLY_HPP_INCLUDED
#define FCPPT_CAST_APPLY_HPP_INCLUDED


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
struct apply
{
	template<
		typename Src
	>
	Res
	operator()(
		Src const &_src
	) const
	{
		return
			Fun :: template execute <
				Res
			>(
				_src
			);
	}
};

}
}

#endif
