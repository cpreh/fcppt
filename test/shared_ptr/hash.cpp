//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/shared_ptr_output.hpp>
#include <fcppt/shared_ptr_std_hash.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	shared_ptr_hash
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::shared_ptr<
		int
	>
	int_shared_ptr;

	typedef
	std::unordered_set<
		int_shared_ptr
	>
	int_shared_ptr_set;

	int_shared_ptr const x(
		fcppt::make_shared_ptr<
			int
		>(
			42
		)
	);

	int_shared_ptr_set const set{
		x
	};

	{
		int_shared_ptr_set::const_iterator const it(
			set.find(
				x
			)
		);

		BOOST_REQUIRE(
			it
			!=
			set.end()
		);

		BOOST_CHECK_EQUAL(
			*it,
			x
		);
	}

	{
		int_shared_ptr const y(
			fcppt::make_shared_ptr<
				int
			>(
				42
			)
		);

		int_shared_ptr_set::const_iterator const it(
			set.find(
				y
			)
		);

		BOOST_CHECK(
			it
			==
			set.end()
		);
	}
}
