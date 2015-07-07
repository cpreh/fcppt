//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DEFAULT_DELETER_HPP_INCLUDED
#define FCPPT_DEFAULT_DELETER_HPP_INCLUDED

#include <fcppt/default_deleter_fwd.hpp>


namespace fcppt
{

/**
\brief A deleter that uses <code>delete</code> to destroy an object.

\ingroup fcpptsmartptr
*/
struct default_deleter
{
	template<
		typename T
	>
	void
	operator()(
		T const *_ptr
	) const
	{
		delete
			_ptr;
	}
};

}

#endif
