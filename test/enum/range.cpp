//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/identity.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/enum/make_range.hpp>
#include <fcppt/enum/make_range_start.hpp>
#include <fcppt/enum/make_range_start_end.hpp>
#include <fcppt/enum/range_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class test_enum
{
	test1,
	test2,
	test3,
	fcppt_maximum = test3
};

typedef
std::vector<
	test_enum
>
enum_vector;

enum_vector
copy_range(
	fcppt::enum_::range<
		test_enum
	> const _range
)
{
	return
		fcppt::algorithm::map<
			enum_vector
		>(
			_range,
			fcppt::identity{}
		);
}

}

TEST_CASE(
	"enum::make_range",
	"[enum]"
)
{
	CHECK(
		copy_range(
			fcppt::enum_::make_range<
				test_enum
			>()
		)
		==
		enum_vector{
			test_enum::test1,
			test_enum::test2,
			test_enum::test3
		}
	);
}

TEST_CASE(
	"enum::make_range_start",
	"[enum]"
)
{
	CHECK(
		copy_range(
			fcppt::enum_::make_range_start(
				test_enum::test2
			)
		)
		==
		enum_vector{
			test_enum::test2,
			test_enum::test3
		}
	);
}

TEST_CASE(
	"enum::make_range_start_end",
	"[enum]"
)
{
	CHECK(
		copy_range(
			fcppt::enum_::make_range_start_end(
				test_enum::test2,
				test_enum::test2
			)
		)
		==
		enum_vector{
			test_enum::test2
		}
	);
}
