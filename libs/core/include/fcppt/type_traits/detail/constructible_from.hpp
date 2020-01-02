//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_DETAIL_CONSTRUCTIBLE_FROM_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_DETAIL_CONSTRUCTIBLE_FROM_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{
namespace detail
{

template<
	typename Type,
	typename... Args
>
class constructible_from
{
        template<
		typename U
	>
        static
	std::true_type
	test(
		U *,
		decltype(
			U(
				std::declval<
					Args
				>()...
			)
		) * = nullptr
	);

        static
	std::false_type
	test(
		...
	);
public:
        typedef
	decltype(
		test(
			std::declval<
				Type *
			>()
		)
	)
	type;
 };

}
}
}

#endif
