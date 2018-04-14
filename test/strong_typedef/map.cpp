//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/insert_to_std_string.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_map.hpp>
#include <fcppt/strong_typedef_tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
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

struct move_test
{
	explicit
	move_test(
		int_unique_ptr &&_ptr
	)
	:
		ptr_{
			std::move(
				_ptr
			)
		}
	{
	}

	int_unique_ptr ptr_;
};

}

BOOST_AUTO_TEST_CASE(
	strong_typedef_map
)
{
	fcppt::strong_typedef<
		std::string,
		fcppt::strong_typedef_tag<
			strong_int
		>
	> const result{
		fcppt::strong_typedef_map(
			strong_int{
				5
			},
			[](
				int const _value
			)
			{
				return
					fcppt::insert_to_std_string(
						_value
					);
			}
		)
	};

	BOOST_CHECK_EQUAL(
		result.get(),
		"5"
	);
}

BOOST_AUTO_TEST_CASE(
	strong_typedef_map_move
)
{
	fcppt::strong_typedef<
		move_test,
		fcppt::strong_typedef_tag<
			strong_int_ptr
		>
	> const result{
		fcppt::strong_typedef_map(
			strong_int_ptr{
				fcppt::make_unique_ptr<
					int
				>(
					5
				)
			},
			[](
				int_unique_ptr &&_ptr
			)
			{
				return
					move_test{
						std::move(
							_ptr
						)
					};
			}
		)
	};

	BOOST_CHECK_EQUAL(
		*result.get().ptr_,
		5
	);
}
