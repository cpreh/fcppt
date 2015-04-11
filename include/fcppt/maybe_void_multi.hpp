//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAYBE_VOID_MULTI_HPP_INCLUDED
#define FCPPT_MAYBE_VOID_MULTI_HPP_INCLUDED

#include <fcppt/maybe_multi.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Transforms optional values or does nothing

\ingroup fcpptoptional

A multi version of \ref fcppt::maybe_void
*/
template<
	typename... Optionals,
	typename Transform
>
inline
void
maybe_void_multi(
	Transform const _transform,
	Optionals &&... _optionals
)
{
	fcppt::maybe_multi(
		[]{},
		_transform,
		std::forward<
			Optionals
		>(
			_optionals
		)...
	);
}

}

#endif
