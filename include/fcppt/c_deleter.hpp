//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_C_DELETER_HPP_INCLUDED
#define FCPPT_C_DELETER_HPP_INCLUDED

#include <fcppt/c_deleter_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief A deleter that uses <code>std::free</code> to destroy an object.

\ingroup fcpptsmartptr

*/
struct c_deleter
{
	/**
	\brief Deletes a pointer using <code>std::free</code>

	Calls <code>std::free(_ptr)</code>

	\param _ptr The pointer to delete

	\tparam T Can be any type where <code>T *</code> can be converted to
	<code>void %*</code>
	*/
	template<
		typename T
	>
	void
	operator()(
		T *const _ptr
	) const
	{
		std::free(
			_ptr
		);
	}
};

}

#endif
