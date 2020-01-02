//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NOT_HPP_INCLUDED
#define FCPPT_NOT_HPP_INCLUDED


namespace fcppt
{

/**
\brief Boolean not.

\ingroup fcpptvarious

This function is a replacement for <code>!</code>.
*/
constexpr
inline
bool
not_(
	bool const _value
)
{
	return
		!_value;
}

}

#endif
