//          Copyright Carl Philipp Reh 2009 - 2016.
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
	typename Type1,
	typename Type2
>
inline
fcppt::homogenous_pair<
	typename
	std::decay<
		Type1
	>::type
>
make_homogenous_pair(
	Type1 &&_first,
	Type2 &&_second
)
{
	static_assert(
		std::is_same<
			typename
			std::decay<
				Type1
			>::type,
			typename
			std::decay<
				Type2
			>::type
		>::value,
		"Type1 and Type2 must be the same decayed type"
	);

	typedef
	typename
	std::decay<
		Type1
	>::type
	result_type;

	return
		fcppt::homogenous_pair<
			result_type
		>(
			std::forward<
				Type1
			>(
				_first
			),
			std::forward<
				Type2
			>(
				_second
			)
		);
}

}

#endif
