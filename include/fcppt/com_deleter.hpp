//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_COM_DELETER_HPP_INCLUDED
#define FCPPT_COM_DELETER_HPP_INCLUDED

namespace fcppt
{

/// Uses object->Release() to destroy an object.
template<
	typename T
>
struct com_deleter
{
	void
	operator()(
		T* const t
	) const
	{
		t->Release();
	}
};

}

#endif
