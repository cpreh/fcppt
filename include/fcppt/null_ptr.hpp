//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NULL_PTR_HPP_INCLUDED
#define FCPPT_NULL_PTR_HPP_INCLUDED

#include <fcppt/null_ptr_t.hpp>


namespace fcppt
{

inline
fcppt::null_ptr_t const
null_ptr()
{
	return fcppt::null_ptr_t();
}

}

#endif
