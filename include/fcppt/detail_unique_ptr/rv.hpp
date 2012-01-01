// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_DETAIL_UNIQUE_PTR_RV_HPP_INCLUDED
#define FCPPT_DETAIL_UNIQUE_PTR_RV_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace detail_unique_ptr
{

template<
	typename T
>
class rv
{
	FCPPT_NONASSIGNABLE(
		rv
	);
public:
	explicit rv(
		T &_r
	)
	:
		r_(_r)
	{}

	T *
	operator->()
	{
		return &r_;
	}

	T &
	operator*()
	{
		return r_;
	}
private:
	T &r_;
};

}
}

#endif
