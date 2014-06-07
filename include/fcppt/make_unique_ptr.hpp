//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_UNIQUE_PTR_HPP_INCLUDED
#define FCPPT_MAKE_UNIQUE_PTR_HPP_INCLUDED

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
std::unique_ptr<
	Res
>
make_unique_ptr(
	Args && ..._args
)
{
	return
		std::unique_ptr<
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
