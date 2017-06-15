//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_ref
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::reference<
		int
	>
	optional_int_ref;

	optional_int_ref const test1{};

	BOOST_CHECK(
		!test1.has_value()
	);

	int val{
		42
	};

	optional_int_ref test2(
		fcppt::make_ref(
			val
		)
	);

	BOOST_CHECK(
		test2.has_value()
	);

	BOOST_CHECK_EQUAL(
		test2.get_unsafe().get(),
		42
	);

	test2 =
		test1;

	BOOST_CHECK(
		!test2.has_value()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_ref_const
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::reference<
		int const
	>
	optional_int_ref_const;

	optional_int_ref_const const test1{};

	BOOST_CHECK(
		!test1.has_value()
	);

	int const val1{
		42
	};

	optional_int_ref_const test2(
		fcppt::make_cref(
			val1
		)
	);

	BOOST_CHECK(
		test2.has_value()
	);

	BOOST_CHECK_EQUAL(
		test2.get_unsafe().get(),
		42
	);

	int val2{
		50
	};

	optional_int_ref_const test3(
		fcppt::make_cref(
			val2
		)
	);

	BOOST_CHECK(
		test3.has_value()
	);

	BOOST_CHECK_EQUAL(
		test3.get_unsafe().get(),
		50
	);

	test3 = test1;

	BOOST_CHECK(
		!test3.has_value()
	);
}
