//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/use.hpp>
#include <fcppt/brigand/runtime_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
unsigned
int_type;

template<
	int_type Value
>
using
int_c
=
std::integral_constant<
	int_type,
	Value
>;

}

BOOST_AUTO_TEST_CASE(
	mpl_runtime_index
)
{
	typedef
	int_c<
		2u
	>
	max_index;

	BOOST_CHECK(
		fcppt::brigand::runtime_index<
			max_index
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
						int_c<
							decltype(
								_type
							)::value
						>,
						int_c<
							0u
						>
					>::value;
			},
			fcppt::const_(
				false
			)
		)
	);

	BOOST_CHECK(
		fcppt::brigand::runtime_index<
			max_index
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
						int_c<
							decltype(
								_type
							)::value
						>,
						int_c<
							1u
						>
					>::value;
			},
			fcppt::const_(
				false
			)
		)
	);

	BOOST_CHECK(
		fcppt::brigand::runtime_index<
			max_index
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
