//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SHARED_PTR_FWD_HPP_INCLUDED
#define FCPPT_SHARED_PTR_FWD_HPP_INCLUDED

#include <fcppt/heap_deleter_fwd.hpp>


namespace fcppt
{

template<
	typename Type,
	typename Deleter = fcppt::heap_deleter
>
class shared_ptr;

}

#endif
