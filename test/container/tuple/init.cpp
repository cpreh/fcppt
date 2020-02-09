//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/container/tuple/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

// TODO:
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

TEST_CASE(
	"tuple::init",
	"[container],[tuple]"
)
{
	typedef
	fcppt::catch_::movable<
		std::size_t
	>
	movable;

	typedef
	std::tuple<
		movable,
		std::size_t
	>
	tuple;

	CHECK(
		fcppt::container::tuple::init<
			tuple
		>(
			overloaded
			{
				[](
					std::integral_constant<
						std::size_t,
						0
					>
				){
					return
						movable{
							0
						};
				},
				[](
					std::integral_constant<
						std::size_t,
						1
					>
				)
				{
					return
						std::size_t{
							1u
						};
				}
			}
		)
		==
		tuple{
			movable{
				0u
			},
			std::size_t{
				1u
			}
		}
	);
}
