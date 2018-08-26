//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef_apply.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_tag.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

typedef
fcppt::unique_ptr<
	int
>
int_unique_ptr;

FCPPT_MAKE_STRONG_TYPEDEF(
	int_unique_ptr,
	strong_int_ptr
);

}

TEST_CASE(
	"strong_typedef_apply",
	"[strongtypedef]"
)
{
	fcppt::strong_typedef<
		std::pair<
			int,
			int
		>,
		fcppt::strong_typedef_tag<
			strong_int
		>
	> const result{
		fcppt::strong_typedef_apply(
			[](
				int const _value1,
				int const _value2
			)
			{
				return
					std::make_pair(
						_value1,
						_value2
					);
			},
			strong_int{
				5
			},
			strong_int{
				42
			}
		)
	};

	CHECK(
		result.get()
		==
		std::make_pair(
			5,
			42
		)
	);
}

TEST_CASE(
	"strong_typedef_apply move",
	"[strongtypedef]"
)
{
	fcppt::strong_typedef<
		std::pair<
			int_unique_ptr,
			int_unique_ptr
		>,
		fcppt::strong_typedef_tag<
			strong_int_ptr
		>
	> const result{
		fcppt::strong_typedef_apply(
			[](
				int_unique_ptr &&_ptr1,
				int_unique_ptr &&_ptr2
			)
			{
				return
					std::make_pair(
						std::move(
							_ptr1
						),
						std::move(
							_ptr2
						)
					);
			},
			strong_int_ptr{
				fcppt::make_unique_ptr<
					int
				>(
					5
				)
			},
			strong_int_ptr{
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			}
		)
	};

	CHECK(
		*result.get().first
		==
		5
	);

	CHECK(
		*result.get().second
		==
		42
	);
}
