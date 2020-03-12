//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DEFAULT_DELETER_HPP_INCLUDED
#define FCPPT_DEFAULT_DELETER_HPP_INCLUDED

#include <fcppt/assert_complete.hpp>
#include <fcppt/default_deleter_fwd.hpp>


namespace fcppt
{

/**
\brief A deleter that uses <code>delete</code> to destroy an object.

\ingroup fcpptsmartptr
*/
struct default_deleter
{
	/**
	\brief Deletes the object using <code>delete</code>

	\tparam T Must be a complete type
	*/
	template<
		typename T
	>
	void
	operator()(
		T const *_ptr
	) const
	{
		FCPPT_ASSERT_COMPLETE(
			T
		);

		// NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
		delete
			_ptr;
	}
};

}

#endif
