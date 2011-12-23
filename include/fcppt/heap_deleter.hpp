//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HEAP_DELETER_HPP_INCLUDED
#define FCPPT_HEAP_DELETER_HPP_INCLUDED

#include <fcppt/assert_complete.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

/**
\brief A deleter that uses <code>delete</code> to destroy an object.

\ingroup fcpptsmartptr

\tparam T Can be any type but must be complete upon deletion
*/
template<
	typename T
>
struct heap_deleter
{
	heap_deleter()
	{
	}

	/**
	\brief Converts a heap deleter if the pointers are also convertible

	If \a U is convertible to \a T, then an
	<code>fcppt::heap_deleter<U></code> is convertible to
	<code>*this</code>

	\tparam U The template parameter of the other <code>heap_deleter</code>
	*/
	template<
		typename U
	>
	heap_deleter(
		fcppt::heap_deleter<U> const &,
		typename boost::enable_if<
			boost::is_convertible<
				U *,
				T *
			>
		>::type * = 0
	)
	{
	}

	/**
	\brief Deletes a pointer using <code>delete</code>

	Calls <code>delete _ptr</code>. When this function is invoked, \tparam
	T must be complete.

	\see FCPPT_ASSSERT_COMPLETE

	\param _ptr The pointer to delete
	*/
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
