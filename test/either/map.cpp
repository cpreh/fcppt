//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	either_map
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either_int;

	typedef
	fcppt::either::object<
		std::string,
		bool
	>
	either_bool;

	auto const map_function(
		[](
			int const _value
		)
		{
			return
				_value
				>
				10;
		}
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::map(
			either_int(
				std::string(
					"test"
				)
			),
			map_function
		),
		either_bool(
			std::string(
				"test"
			)
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::either::map(
			either_int(
				20
			),
			map_function
		),
		either_bool(
			true
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	either_map_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::either::object<
		std::string,
		fcppt::unique_ptr<
			int
		>
	>
	either_int;

	FCPPT_MAKE_STRONG_TYPEDEF(
		fcppt::unique_ptr<
			int
		>,
		strong_int
	);

	auto const map_function(
		[](
			fcppt::unique_ptr<
				int
			> &&_ptr
		)
		{
			return
				strong_int{
					std::move(
						_ptr
					)
				};
		}
	);

	BOOST_CHECK(
		fcppt::either::match(
			fcppt::either::map(
				either_int(
					fcppt::make_unique_ptr<
						int
					>(
						20
					)
				),
				map_function
			),
			[](
				std::string const &
			)
			{
				return
					false;
			},
			[](
				strong_int const &_value
			)
			{
				return
					*_value.get()
					==
					20;
			}
		)
	);
}
