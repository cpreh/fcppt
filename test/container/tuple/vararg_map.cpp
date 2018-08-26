//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/tuple/vararg_map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tuple::vararg_map",
	"[container],[tuple]"
)
{
	CHECK(
		fcppt::container::tuple::vararg_map(
			std::tuple<
				fcppt::tag<
					int
				>,
				fcppt::tag<
					long
				>
			>{},
			[](
				auto const &... _args
			){
				return
					std::make_tuple(
						_args...
					);
			},
			[](
				auto const _tag
			)
			{
				FCPPT_USE(
					_tag
				);

				return
					fcppt::cast::to_unsigned(
						fcppt::literal<
							fcppt::tag_type<
								decltype(
									_tag
								)
							>
						>(
							42
						)
					);
			}
		)
		==
		std::tuple<
			unsigned,
			unsigned long
		>{
			42u,
			42uL
		}
	);
}

TEST_CASE(
	"container::tuple::vararg_map move",
	"[container],[tuple]"
)
{
	typedef
	fcppt::catch_::movable<
		int
	>
	movable;

	CHECK(
		fcppt::container::tuple::vararg_map(
			std::make_tuple(
				movable{
					42
				}
			),
			[](
				auto && _args
			){
				return
					std::forward<
						decltype(
							_args
						)
					>(
						_args
					);
			},
			[](
				auto &&_arg
			)
			{
				return
					std::forward<
						decltype(
							_arg
						)
					>(
						_arg
					);
			}
		)
		==
		movable{
			42
		}
	);
}
