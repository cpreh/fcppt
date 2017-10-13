//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/container/pop_back.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_pop_back
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector empty{};

	BOOST_CHECK(
		!fcppt::container::pop_back(
			empty
		).has_value()
	);

	int_vector vec12{
		1,
		2
	};

	BOOST_CHECK_EQUAL(
		fcppt::container::pop_back(
			vec12
		),
		fcppt::optional::make(
			2
		)
	);

	int_vector const expected{
		1
	};

	BOOST_CHECK(
		vec12
		==
		expected
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_pop_back_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		int
	>
	int_ptr;

	typedef
	std::vector<
		int_ptr
	>
	int_ptr_vector;

	int_ptr_vector vector(
		fcppt::assign::make_container<
			int_ptr_vector
		>(
			fcppt::make_unique_ptr<
				int
			>(
				42
			)
		)
	);

	fcppt::optional::maybe(
		fcppt::container::pop_back(
			vector
		),
		[]{
			BOOST_CHECK(
				false
			);
		},
		[](
			int_ptr &&_ptr
		)
		{
			BOOST_CHECK_EQUAL(
				*_ptr,
				42
			);
		}
	);

	BOOST_CHECK(
		vector.empty()
	);
}
