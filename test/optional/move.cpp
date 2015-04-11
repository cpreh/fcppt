//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

class movable
{
	FCPPT_NONCOPYABLE(
		movable
	);
public:
	explicit
	movable(
		std::string const &_value
	)
	:
		value_(
			_value
		)
	{
	}

	movable(
		movable &&
	) = default;

	movable &
	operator=(
		movable &&
	) = default;

	~movable()
	{
	}

	std::string const &
	value() const
	{
		return
			value_;
	}
private:
	std::string value_;
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_move
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::optional<
		movable
	> optional_movable;


	optional_movable opta(
		movable(
			"test"
		)
	);

	optional_movable optb(
		std::move(
			opta
		)
	);

	BOOST_REQUIRE(
		!opta.has_value()
	);

	BOOST_REQUIRE(
		optb.has_value()
	);

	BOOST_CHECK_EQUAL(
		optb.get_unsafe().value(),
		"test"
	);

	optional_movable optc(
		movable(
			"test2"
		)
	);

	optc =
		std::move(
			optb
		);

	BOOST_REQUIRE(
		optc.has_value()
	);

	BOOST_REQUIRE(
		!optb.has_value()
	);

	BOOST_CHECK(
		optc.get_unsafe().value()
		==
		"test"
	);

	optional_movable optd;

	optd =
		optional_movable(
			movable(
				"test3"
			)
		);

	BOOST_CHECK(
		optd.get_unsafe().value()
		==
		"test3"
	);

	optd =
		optional_movable(
			movable(
				"test4"
			)
		);

	BOOST_CHECK(
		optd.get_unsafe().value()
		==
		"test4"
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_move_ref
)
{
FCPPT_PP_POP_WARNING
	typedef
	fcppt::optional<
		int &
	>
	optional_int_ref;


	int val{
		42
	};

	optional_int_ref test(
		val
	);

	optional_int_ref test2(
		std::move(
			test
		)
	);

	BOOST_CHECK(
		!test.has_value()
	);

	BOOST_REQUIRE(
		test2.has_value()
	);

	BOOST_CHECK_EQUAL(
		test2.get_unsafe(),
		42
	);

	optional_int_ref test3;

	test3 =
		std::move(
			test2
		);

	BOOST_REQUIRE(
		test3.has_value()
	);

	BOOST_CHECK(
		!test2.has_value()
	);

	BOOST_CHECK_EQUAL(
		test3.get_unsafe(),
		42
	);
}
