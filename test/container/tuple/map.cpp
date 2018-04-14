//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/use.hpp>
#include <fcppt/container/tuple/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	tuple_map
)
{
	std::tuple<
		std::integral_constant<
			int,
			2
		>,
		std::integral_constant<
			int,
			3
		>
	> const result{
		fcppt::container::tuple::map(
			std::make_tuple(
				std::integral_constant<
					int,
					1
				>{},
				std::integral_constant<
					int,
					2
				>{}
			),
			[](
				auto const _arg
			)
			{
				return
					std::integral_constant<
						int,
						std::remove_const_t<
							decltype(
								_arg
							)
						>::value
						+
						1u
					>{};
			}
		)
	};

	FCPPT_USE(
		result
	);
}

BOOST_AUTO_TEST_CASE(
	tuple_map_move
)
{
	FCPPT_MAKE_STRONG_TYPEDEF(
		fcppt::unique_ptr<
			int
		>,
		strong_unique_ptr
	);

	std::tuple<
		strong_unique_ptr
	> const result{
		fcppt::container::tuple::map(
			std::make_tuple(
				fcppt::make_unique_ptr<
					int
				>(
					1
				)
			),
			[](
				fcppt::unique_ptr<
					int
				> &&_ptr
			)
			{
				return
					strong_unique_ptr{
						std::move(
							_ptr
						)
					};
			}
		)
	};

	BOOST_CHECK_EQUAL(
		*std::get<
			0
		>(
			result
		).get(),
		1
	);
}
