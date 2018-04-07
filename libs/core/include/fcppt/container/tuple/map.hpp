//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_MAP_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_MAP_HPP_INCLUDED

#include <fcppt/container/tuple/map_result.hpp>
#include <fcppt/container/tuple/detail/map.hpp>
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
\brief Maps over a tuple.

\ingroup fcpptcontainertuple

Let \a _tuple be <code>(v_1,...,v_n)</code>.
The result of the function is the tuple <code>(_function(v_1),...,_function(v_n))</code>.

\tparam Tuple Must be a <code>std::tuple</code>.

\tparam Function Must be callable with every type in \a Tuple.
*/
template<
	typename Tuple,
	typename Function
>
inline
auto
map(
	Tuple &&_tuple,
	Function const &_function
)
->
fcppt::container::tuple::map_result<
	Tuple,
	Function
>
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Tuple
	>
	source_type;

	static_assert(
		fcppt::type_traits::is_std_tuple<
			source_type
		>::value,
		"Tuple must be a std::tuple"
	);

	return
		fcppt::container::tuple::detail::map<
			fcppt::container::tuple::map_result<
				Tuple,
				Function
			>
		>(
			std::make_index_sequence<
				std::tuple_size<
					source_type
				>::value
			>{},
			std::forward<
				Tuple
			>(
				_tuple
			),
			_function
		);
}

}
}
}

#endif
