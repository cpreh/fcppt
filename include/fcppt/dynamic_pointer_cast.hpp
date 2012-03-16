//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DYNAMIC_POINTER_CAST_HPP_INCLUDED
#define FCPPT_DYNAMIC_POINTER_CAST_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

/**
\brief Casts an \link fcppt::shared_ptr \endlink using
<code>dynamic_cast</code>

\ingroup fcpptsmartptr

Casts the pointer stored in \a _ptr to type <code>U *</code> using
<code>dynamic_cast</code>. This means that <code>T *</code> and <code>U
*</code> be members of the same class hierarchy. If the cast succeeds, the
resulting shared_ptr will share ownership with the source.

\tparam Dest The type of the destination shared_ptr

\tparam Source The type of the source shared_ptr

\param _ptr The source shared_ptr

\return The converted shared_ptr or an empty shared_ptr if the
<code>dynamic_cast</code> fails
*/
template<
	typename Dest,
	typename Source,
	typename Deleter
>
fcppt::shared_ptr<
	Dest,
	Deleter
> const
dynamic_pointer_cast(
	fcppt::shared_ptr<
		Source,
		Deleter
	> const &_ptr
)
{
	return
		fcppt::shared_ptr<
			Dest,
			Deleter
		>(
			_ptr,
			boost::detail::dynamic_cast_tag()
		);
}

}

#endif
