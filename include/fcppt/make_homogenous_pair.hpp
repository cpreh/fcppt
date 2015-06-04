//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_HOMOGENOUS_PAIR_HPP_INCLUDED
#define FCPPT_MAKE_HOMOGENOUS_PAIR_HPP_INCLUDED

#include <fcppt/homogenous_pair_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Like <code>std::make_pair</code> for fcppt::homogenous_pair

\ingroup fcpptvarious
*/
template<
	typename Type
>
inline
fcppt::homogenous_pair<
	typename
	std::decay<
		Type
	>::type
>
make_homogenous_pair(
	Type &&_first,
	Type &&_second
)
{
	return
		fcppt::homogenous_pair<
			Type
		>(
			std::forward<
				Type
			>(
				_first
			),
			std::forward<
				Type
			>(
				_second
			)
		);
}

}

#endif
