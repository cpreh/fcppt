//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/assign/make_container_opt.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

class movable
{
	FCPPT_NONCOPYABLE(
		movable
	);
public:
	movable()
	{
	}

	movable(
		movable &&
	) = default;

	movable &
	operator=(
		movable &&
	) = default;
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	assign_make_container_opt
)
{
FCPPT_PP_POP_WARNING
	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	fcppt::optional<
		int
	>
	optional_int;

	int_vector const result(
		fcppt::assign::make_container_opt<
			int_vector
		>(
			42,
			optional_int(),
			optional_int(
				100
			),
			500
		)
	);

	BOOST_REQUIRE(
		result.size()
		==
		3u
	);

	BOOST_CHECK(
		result[0]
		==
		42
	);

	BOOST_CHECK(
		result[1]
		==
		100
	);

	BOOST_CHECK(
		result[2]
		==
		500
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	assign_make_container_opt_move
)
{
FCPPT_PP_POP_WARNING
	typedef
	std::vector<
		movable
	>
	movable_vector;

	typedef
	fcppt::optional<
		movable
	>
	optional_movable;

	movable_vector const result(
		fcppt::assign::make_container_opt<
			movable_vector
		>(
			movable(),
			optional_movable(),
			optional_movable(
				movable()
			)
		)
	);

	BOOST_CHECK(
		result.size()
		==
		2u
	);
}
