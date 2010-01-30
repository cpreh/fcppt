//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_C_DELETER_HPP_INCLUDED
#define FCPPT_C_DELETER_HPP_INCLUDED

#include <cstdlib>

namespace fcppt
{

/// Uses std::free(object) to destroy an object.
template<
	typename T
>
struct c_deleter
{
	void
	operator()(
		T *const t
	) const
	{
		std::free(t);
	}
};

}

#endif
