//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_UNIQUE_PTR_FCPPT_HPP_INCLUDED
#define FCPPT_MAKE_UNIQUE_PTR_FCPPT_HPP_INCLUDED

#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename Res,
	typename... Args
>
fcppt::unique_ptr<
	Res
>
make_unique_ptr_fcppt(
	Args && ..._args
)
{
	return
		fcppt::unique_ptr<
			Res
		>(
			new Res(
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