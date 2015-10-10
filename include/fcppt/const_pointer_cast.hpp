//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONST_POINTER_CAST_HPP_INCLUDED
#define FCPPT_CONST_POINTER_CAST_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>


namespace fcppt
{

/**
\brief Casts an \link fcppt::shared_ptr \endlink using
<code>const_cast</code>

\ingroup fcpptsmartptr

Casts the pointer stored in \a _ptr to type <code>U *</code> using
<code>const_cast</code>.

\tparam Dest The type of the destination shared_ptr

\tparam Source The type of the source shared_ptr

\param _ptr The source shared_ptr

\return The converted shared_ptr
*/
template<
	typename Dest,
	typename Source
>
fcppt::shared_ptr<
	Dest
>
const_pointer_cast(
	fcppt::shared_ptr<
		Source const
	> const &_ptr
)
{
	return
		fcppt::shared_ptr<
			Dest
		>(
			_ptr,
			const_cast<
				Dest *
			>(
				_ptr.get_pointer()
			)
		);
}

}

#endif
