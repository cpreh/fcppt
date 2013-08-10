//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UNIQUE_PTR_TO_OPTIONAL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_TO_OPTIONAL_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Transforms a unique_ptr into an optional reference

\ingroup fcpptoptional

Transforms \a _ptr into an optional reference. If \a _ptr is null, then an
empty optional is returned, otherwise an optional reference to the object held
by \a _ptr is returned.

\tparam Type Can be any object type

\param _ptr The pointer to transform into an optional reference
*/
template<
	typename Type
>
fcppt::optional<
	Type &
> const
unique_ptr_to_optional(
	std::unique_ptr<
		Type
	> const &_ptr
)
{
	typedef
	fcppt::optional<
		Type &
	>
	result_type;

	return
		_ptr
		?
			result_type(
				*_ptr
			)
		:
			result_type()
		;
}

}

#endif
