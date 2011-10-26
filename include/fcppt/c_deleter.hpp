//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_C_DELETER_HPP_INCLUDED
#define FCPPT_C_DELETER_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>

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
