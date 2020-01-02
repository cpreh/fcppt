//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_MAYBE_VOID_MULTI_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAYBE_VOID_MULTI_HPP_INCLUDED

#include <fcppt/optional/maybe_multi.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Transforms optional values or does nothing

\ingroup fcpptoptional

A multi version of \ref fcppt::optional::maybe_void
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
	fcppt::optional::maybe_multi(
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
}

#endif
