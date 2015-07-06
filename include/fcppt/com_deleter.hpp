//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_COM_DELETER_HPP_INCLUDED
#define FCPPT_COM_DELETER_HPP_INCLUDED

#include <fcppt/com_deleter_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief A deleter that uses the <code>Release</code> member function to destroy
an object.

\ingroup fcpptsmartptr

COM objects have a reference counting mechanism where calling
<code>Release</code> on them decrements the reference counter. This mechanism
is enabled by deriving from <code>IUnknown</code>

\tparam T Must derive from <code>IUnknown</code>
*/
template<
	typename T
>
struct com_deleter
{
	com_deleter()
	{
	}

	template<
		typename U,
		typename =
			typename
			boost::enable_if<
				std::is_convertible<
					U,
					T
				>
			>::type
	>
	com_deleter(
		com_deleter<
			U
		> const &
	)
	{
	}

	/**
	\brief Deletes a pointer using <code>Release</code>

	Calls <code>_ptr->Release()</code> if _ptr is not NULL

	\param _ptr The pointer to delete, can be NULL
	*/
	void
	operator()(
		T* const _ptr
	) const
	{
		if(
			_ptr
		)
			_ptr->Release();
	}
};

}

#endif
