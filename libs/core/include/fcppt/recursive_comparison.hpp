//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECURSIVE_COMPARISON_HPP_INCLUDED
#define FCPPT_RECURSIVE_COMPARISON_HPP_INCLUDED

#include <fcppt/recursive_impl.hpp>


namespace fcppt
{

/**
\brief Compares two \link fcppt::recursive\endlink for equality.

\ingroup fcpptvarious
*/
template<
	typename Type
>
bool
operator==(
	fcppt::recursive<
		Type
	> const &_left,
	fcppt::recursive<
		Type
	> const &_right
)
{
	return
		_left.get()
		==
		_right.get();
}

/**
\brief Compares two \link fcppt::recursive\endlink for inequality.

\ingroup fcpptvarious
*/
template<
	typename Type
>
bool
operator!=(
	fcppt::recursive<
		Type
	> const &_left,
	fcppt::recursive<
		Type
	> const &_right
)
{
	return
		!(
			_left
			==
			_right
		);
}

}

#endif
