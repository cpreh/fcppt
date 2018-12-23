//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_MAKE_TUPLE_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_MAKE_TUPLE_HPP_INCLUDED

#include <fcppt/not.hpp>
#include <fcppt/type_traits/is_std_tuple.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

template<
	typename Type
>
std::enable_if_t<
	fcppt::type_traits::is_std_tuple<
		fcppt::type_traits::remove_cv_ref_t<
			Type
		>
	>,
	fcppt::type_traits::remove_cv_ref_t<
		Type
	>
>
make_tuple(
	Type &&_value
)
{
	return
		std::forward<
			Type
		>(
			_value
		);
}

template<
	typename Type
>
std::enable_if_t<
	fcppt::not_(
		fcppt::type_traits::is_std_tuple<
			fcppt::type_traits::remove_cv_ref_t<
				Type
			>
		>
	),
	std::tuple<
		fcppt::type_traits::remove_cv_ref_t<
			Type
		>
	>
>
make_tuple(
	Type &&_value
)
{
	return
		std::make_tuple(
			std::forward<
				Type
			>(
				_value
			)
		);
}

}
}
}

#endif
