//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/metal/invoke_on.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"metal::invoke_on",
	"[metal]"
)
{
	typedef
	metal::list<
		int,
		long
	>
	list_type;

	CHECK(
		fcppt::metal::invoke_on<
			list_type
		>(
			1u,
			[](
				auto const _type
			)
			-> bool
			{
				FCPPT_USE(
					_type
				);

				return
					std::is_same<
						fcppt::tag_type<
							decltype(
								_type
							)
						>,
						long
					>::value;
			},
			fcppt::const_(
				false
			)
		)
	);

	CHECK(
		fcppt::metal::invoke_on<
			list_type
		>(
			0u,
			[](
				auto const _type
			)
			-> bool
			{
				FCPPT_USE(
					_type
				);

				return
					std::is_same<
						fcppt::tag_type<
							decltype(
								_type
							)
						>,
						int
					>::value;
			},
			fcppt::const_(
				false
			)
		)
	);

	CHECK(
		fcppt::metal::invoke_on<
			list_type
		>(
			2u,
			[](
				auto
			)
			-> bool
			{
				return
					false;
			},
			fcppt::const_(
				true
			)
		)
	);
}
