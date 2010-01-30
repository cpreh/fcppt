//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HEAP_DELETER_HPP_INCLUDED
#define FCPPT_HEAP_DELETER_HPP_INCLUDED

namespace fcppt
{

/// Uses delete object to destroy an object.
template<
	typename T
>
struct heap_deleter
{
	void
	operator()(
		T *const t
	) const
	{
		delete t;
	}
};

}

#endif
