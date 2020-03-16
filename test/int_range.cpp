//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/identity.hpp>
#include <fcppt/int_iterator_impl.hpp>
#include <fcppt/int_range_impl.hpp>
#include <fcppt/make_int_range.hpp>
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/make_literal_strong_typedef.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/type_iso/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename Iterator
>
void
check_category()
{
	static_assert(
		std::is_same_v<
			typename
			Iterator::iterator_category,
			std::input_iterator_tag
		>
	);
}

static_assert(
	std::is_same_v<
		fcppt::int_iterator<
			int
		>::iterator_category,
		std::input_iterator_tag
	>
);

template<
	typename Int
>
std::vector<
	Int
>
copy_range(
	fcppt::int_range<
		Int
	> const _range
)
{
	check_category<
		decltype(
			_range.begin()
		)
	>();

	return
		fcppt::algorithm::map<
			std::vector<
				Int
			>
		>(
			_range,
			fcppt::identity{}
		);
}

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

}

TEST_CASE(
	"make_int_range",
	"[various]"
)
{
	CHECK(
		copy_range(
			fcppt::make_int_range(
				0,
				3
			)
		)
		==
		std::vector<
			int
		>{
			0,
			1,
			2
		}
	);
}

TEST_CASE(
	"make_int_range_count",
	"[various]"
)
{
	CHECK(
		copy_range(
			fcppt::make_int_range_count(
				2
			)
		)
		==
		std::vector<
			int
		>{
			0,
			1
		}
	);
}

TEST_CASE(
	"make_int_range_count strong_typedef",
	"[various]"
)
{
	CHECK(
		copy_range(
			fcppt::make_int_range_count(
				strong_int(
					2
				)
			)
		)
		==
		std::vector<
			strong_int
		>{
			strong_int(
				0
			),
			strong_int(
				1
			)
		}
	);
}

TEST_CASE(
	"int_range empty",
	"[various]"
)
{
	CHECK(
		copy_range(
			fcppt::make_int_range(
				3,
				2
			)
		).empty()
	);
}
