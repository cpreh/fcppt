//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_SHARED_PTR_HPP_INCLUDED
#define FCPPT_MAKE_SHARED_PTR_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/detail/make_ptr_base.hpp>
#include <fcppt/detail/make_shared_wrapper.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

FCPPT_DETAIL_MAKE_PTR_BASE(
	shared_ptr,
	fcppt::detail::make_shared_wrapper,
	std::make_shared<
		Type
	>
)

}

#endif
