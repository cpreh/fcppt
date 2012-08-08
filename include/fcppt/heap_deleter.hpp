//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HEAP_DELETER_HPP_INCLUDED
#define FCPPT_HEAP_DELETER_HPP_INCLUDED

#include <fcppt/assert_complete.hpp>
#include <fcppt/heap_deleter_fwd.hpp>


namespace fcppt
{

/**
\brief A deleter that uses <code>delete</code> to destroy an object.

\ingroup fcpptsmartptr
*/
struct heap_deleter
{
	/**
	\brief Deletes a pointer using <code>delete</code>

	Calls <code>delete _ptr</code>. When this function is invoked, \tparam
	T must be complete.

	\see FCPPT_ASSSERT_COMPLETE

	\param _ptr The pointer to delete

	\tparam T Can be any type but must be complete upon deletion
	*/
	template<
		typename T
	>
	void
	operator()(
		T *const _ptr
	) const
	{
		FCPPT_ASSERT_COMPLETE(
			T
		);

		delete _ptr;
	}
};

}

#endif
