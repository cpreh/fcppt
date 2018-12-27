//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_VARARG_MAP_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_VARARG_MAP_HPP_INCLUDED

#include <fcppt/container/tuple/map.hpp>
#include <fcppt/type_traits/is_std_tuple.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tuple
{

/**
\brief Combination of \link fcppt::container::tuple::map\endlink and <code>std::apply</code>.

\ingroup fcpptcontainertuple

\tparam Tuple Must be a <code>std::tuple</code>.
*/
template<
	typename Tuple,
	typename AnchorFunction,
	typename ElementFunction
>
inline
decltype(
	auto
)
vararg_map(
	Tuple &&_tuple,
	AnchorFunction const &_anchor_function,
	ElementFunction const &_element_function
)
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Tuple
	>
	tuple_type;

	static_assert(
		fcppt::type_traits::is_std_tuple<
			tuple_type
		>::value,
		"Tuple must be a tuple"
	);

	return
		std::apply(
			_anchor_function,
			fcppt::container::tuple::map(
				std::forward<
					Tuple
				>(
					_tuple
				),
				_element_function
			)
		);
}

}
}
}

#endif
