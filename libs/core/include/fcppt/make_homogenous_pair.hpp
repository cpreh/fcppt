//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_HOMOGENOUS_PAIR_HPP_INCLUDED
#define FCPPT_MAKE_HOMOGENOUS_PAIR_HPP_INCLUDED

#include <fcppt/homogenous_pair_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
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
	fcppt::type_traits::remove_cv_ref_t<
		Type1
	>
>
make_homogenous_pair(
	Type1 &&_first,
	Type2 &&_second
)
{
	static_assert(
		std::is_same<
			fcppt::type_traits::remove_cv_ref_t<
				Type1
			>,
			fcppt::type_traits::remove_cv_ref_t<
				Type2
			>
		>::value,
		"Type1 and Type2 must be the same decayed type"
	);

	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Type1
	>
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
