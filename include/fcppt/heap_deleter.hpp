//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HEAP_DELETER_HPP_INCLUDED
#define FCPPT_HEAP_DELETER_HPP_INCLUDED

#include <fcppt/assert_complete.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{

/// Uses delete object to destroy an object.
template<
	typename T
>
struct heap_deleter
{
	heap_deleter()
	{
	}
      
	template<
		typename U
	>
	heap_deleter(
		heap_deleter<U> const &,
		typename boost::enable_if<
			boost::is_convertible<
				U *,
				T *
			>
		>::type * = 0
	)
	{
	}

	void
	operator()(
		T *const _ptr
	) const
	{
		FCPPT_ASSERT_COMPLETE(T)

		delete _ptr;
	}
};

}

#endif
