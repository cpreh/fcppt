//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SHARED_PTR_FWD_HPP_INCLUDED
#define FCPPT_SHARED_PTR_FWD_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename Type,
	typename Deleter =
		std::default_delete<
			Type
		>
>
class shared_ptr;

}

#endif
