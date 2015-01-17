//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_SHARED_PTR_HPP_INCLUDED
#define FCPPT_MAKE_SHARED_PTR_HPP_INCLUDED

#include <fcppt/detail/make_shared_wrapper.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename Res,
	typename... Args
>
fcppt::detail::make_shared_wrapper<
	Res
>
make_shared_ptr(
	Args && ..._args
)
{
	return
		fcppt::detail::make_shared_wrapper<
			Res
		>(
			std::make_shared<
				Res
			>(
				std::forward<
					Args
				>(
					_args
				)...
			)
		);
}

}

#endif
