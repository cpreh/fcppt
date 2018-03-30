//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_PUSH_BACK_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_PUSH_BACK_HPP_INCLUDED

#include <fcppt/container/tuple_push_back_result.hpp>
#include <fcppt/container/detail/tuple_push_back.hpp>
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

template<
	typename Source,
	typename NewElement
>
fcppt::container::tuple_push_back_result<
	fcppt::type_traits::remove_cv_ref_t<
		Source
	>,
	fcppt::type_traits::remove_cv_ref_t<
		NewElement
	>
>
tuple_push_back(
	Source &&_source,
	NewElement &&_new_element
)
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Source
	>
	source_type;

	static_assert(
		fcppt::type_traits::is_std_tuple<
			source_type
		>::value,
		"Source must be a std::tuple"
	);

	return
		fcppt::container::detail::tuple_push_back<
			fcppt::container::tuple_push_back_result<
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
				Source
			>(
				_source
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

#endif
