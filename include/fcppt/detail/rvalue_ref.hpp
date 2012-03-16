// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_DETAIL_RVALUE_REF_HPP_INCLUDED
#define FCPPT_DETAIL_RVALUE_REF_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/detail/rvalue_ref_fwd.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Type
>
class rvalue_ref
{
	FCPPT_NONASSIGNABLE(
		rvalue_ref
	);
public:
	explicit
	rvalue_ref(
		Type &_rvalue
	)
	:
		rvalue_(
			_rvalue
		)
	{
	}

	Type *
	operator->()
	{
		return &rvalue_;
	}

	Type &
	operator*()
	{
		return rvalue_;
	}
private:
	Type &rvalue_;
};

}
}

#endif
