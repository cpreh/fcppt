//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IDENTITY_HPP_INCLUDED
#define FCPPT_IDENTITY_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief The identity function

\ingroup fcpptvarious
*/
struct identity
{
	template<
		typename T
	>
	auto
	operator()(
		T &&_t
	) const
	-> decltype(
		std::forward<
			T
		>(
			_t
		)
	)
	{
		return
			std::forward<
				T
			>(
				_t
			);
	}
};

}

#endif
