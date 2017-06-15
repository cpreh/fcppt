//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/deref.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
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
	optional_deref_unique_ptr
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional::object<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	optional_int_unique_ptr const opt_ptr(
		fcppt::make_unique_ptr<
			int
		>(
			42
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional::deref(
			opt_ptr
		),
		fcppt::optional::reference<
			int
		>(
			fcppt::make_ref(
				*opt_ptr.get_unsafe()
			)
		)
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_deref_vector
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector ints{
		1,
		2,
		3
	};

	BOOST_CHECK_EQUAL(
		fcppt::optional::deref(
			fcppt::optional::object<
				int_vector::iterator
			>(
				ints.begin()
			)
		),
		fcppt::optional::reference<
			int
		>(
			fcppt::make_ref(
				ints.front()
			)
		)
	);

	int const &const_front(
		ints.front()
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional::deref(
			fcppt::optional::object<
				int_vector::const_iterator
			>(
				ints.cbegin()
			)
		),
		fcppt::optional::reference<
			int const
		>(
			fcppt::make_cref(
				const_front
			)
		)
	);
}
