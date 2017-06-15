//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_TO_POINTER_HPP_INCLUDED
#define FCPPT_OPTIONAL_TO_POINTER_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/reference.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Converts an optional reference to a pointer

\ingroup fcpptoptional

If \a _optional is empty, returns <code>nullptr</code>. Otherwise, returns the
address of the referenced object of \a _optional.
*/
template<
	typename T
>
inline
T *
to_pointer(
	fcppt::optional::reference<
		T
	> const _optional
)
{
	return
		fcppt::optional::maybe(
			_optional,
			[]()
			-> T *
			{
				return
					nullptr;
			},
			[](
				fcppt::reference<
					T
				> const _ref
			)
			{
				return
					&_ref.get();
			}
		);
}

}
}

#endif
