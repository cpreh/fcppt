//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/multiply_disjoint.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	record_multiply_disjoint
)
{
FCPPT_PP_POP_WARNING

	FCPPT_RECORD_MAKE_LABEL(
		int_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		move_only_label
	);

	typedef
	fcppt::record::element<
		int_label,
		int
	>
	int_element;

	typedef
	fcppt::record::element<
		move_only_label,
		fcppt::unique_ptr<
			int
		>
	>
	move_only_element;

	typedef
	fcppt::record::variadic<
		int_element
	>
	record1;

	typedef
	fcppt::record::variadic<
		move_only_element
	>
	record2;

	record1 const arg1{
		int_label{} =
			42
	};

	auto const result{
		fcppt::record::multiply_disjoint(
			arg1,
			record2{
				move_only_label{} =
					fcppt::make_unique_ptr<
						int
					>(
						100
					)
			}
		)
	};

	BOOST_CHECK_EQUAL(
		fcppt::record::get<
			int_label
		>(
			result
		),
		42
	);

	BOOST_CHECK_EQUAL(
		*fcppt::record::get<
			move_only_label
		>(
			result
		),
		100
	);
}
