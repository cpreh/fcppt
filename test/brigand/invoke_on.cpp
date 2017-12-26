//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/brigand/invoke_on.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <brigand/sequences/list.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	mpl_invoke_on
)
{
	typedef
	brigand::list<
		int,
		long
	>
	list_type;

	BOOST_CHECK(
		fcppt::brigand::invoke_on<
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

	BOOST_CHECK(
		fcppt::brigand::invoke_on<
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

	BOOST_CHECK(
		fcppt::brigand::invoke_on<
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
