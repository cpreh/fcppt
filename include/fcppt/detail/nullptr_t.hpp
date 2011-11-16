//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_NULLPTR_T_HPP_INCLUDED
#define FCPPT_DETAIL_NULLPTR_T_HPP_INCLUDED

namespace fcppt
{
namespace detail
{

struct nullptr_t
{
	template<
		typename T
	>
	operator T*() const
	{
		return 0;
	}
};

}
}

#endif
