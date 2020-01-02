//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DEREF_HPP_INCLUDED
#define FCPPT_DEREF_HPP_INCLUDED

#include <fcppt/deref_impl.hpp>


namespace fcppt
{

/**
\brief Dereferences an object.

\ingroup fcpptvarious

Calls fcppt::deref_impl::execute to dereference \a _arg.
*/
template<
	typename Arg
>
inline
decltype(
	auto
)
deref(
	Arg &_arg
)
{
	return
		fcppt::deref_impl<
			Arg
		>::execute(
			_arg
		);
}

}

#endif
