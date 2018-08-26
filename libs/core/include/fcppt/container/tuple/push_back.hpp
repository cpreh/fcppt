//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_PUSH_BACK_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_PUSH_BACK_HPP_INCLUDED

#include <fcppt/container/tuple/push_back_result.hpp>
#include <fcppt/container/tuple/detail/push_back.hpp>
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
\brief Pushes an element to the back of a <code>std::tuple</code>.

\ingroup fcpptcontainertuple

Let \a _tuple be <code>(v_1,...,v_n)</code>.
The result of the function is <code>(v_1,...,v_n,_new_element)</code>.

\tparam Tuple Must be a <code>std::tuple</code>.
*/
template<
	typename Tuple,
	typename NewElement
>
fcppt::container::tuple::push_back_result<
	fcppt::type_traits::remove_cv_ref_t<
		Tuple
	>,
	fcppt::type_traits::remove_cv_ref_t<
		NewElement
	>
>
push_back(
	Tuple &&_tuple,
	NewElement &&_new_element
)
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
		fcppt::container::tuple::detail::push_back<
			fcppt::container::tuple::push_back_result<
				source_type,
				fcppt::type_traits::remove_cv_ref_t<
					NewElement
				>
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
			std::forward<
				NewElement
			>(
				_new_element
			)
		);
}

}
}
}

#endif
