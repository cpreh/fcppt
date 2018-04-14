//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_apply.hpp>
#include <fcppt/strong_typedef_tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
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

BOOST_AUTO_TEST_CASE(
	strong_typedef_apply
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

	BOOST_CHECK_EQUAL(
		result.get().first,
		5
	);

	BOOST_CHECK_EQUAL(
		result.get().second,
		42
	);
}

BOOST_AUTO_TEST_CASE(
	strong_typedef_apply_move
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

	BOOST_CHECK_EQUAL(
		*result.get().first,
		5
	);

	BOOST_CHECK_EQUAL(
		*result.get().second,
		42
	);
}
