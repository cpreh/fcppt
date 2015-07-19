//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DYNAMIC_POINTER_CAST_HPP_INCLUDED
#define FCPPT_DYNAMIC_POINTER_CAST_HPP_INCLUDED

#include <fcppt/optional_bind_construct.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/cast/try_dynamic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Casts an \link fcppt::shared_ptr \endlink using
<code>dynamic_cast</code>

\ingroup fcpptsmartptr

Casts the pointer stored in \a _ptr to type <code>U *</code> using
<code>dynamic_cast</code>. This means that <code>T *</code> and <code>U
*</code> must be members of the same class hierarchy. If the cast succeeds,
the resulting shared_ptr will share ownership with the source.

\tparam Dest The type of the destination shared_ptr

\tparam Source The type of the source shared_ptr

\param _ptr The source shared_ptr
*/
template<
	typename Dest,
	typename Source
>
fcppt::optional<
	fcppt::shared_ptr<
		Dest
	>
>
dynamic_pointer_cast(
	fcppt::shared_ptr<
		Source
	> const &_ptr
)
{
	return
		fcppt::optional_bind_construct(
			fcppt::cast::try_dynamic<
				typename
				std::remove_pointer<
					Dest
				>::type &
			>(
				*_ptr
			),
			[
				&_ptr
			](
				Dest &_dest
			)
			{
				return
					fcppt::shared_ptr<
						Dest
					>(
						_ptr,
						&_dest
					);
			}
		);
}

}

#endif
