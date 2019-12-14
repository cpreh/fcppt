//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/multiply_disjoint.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"record::multiply_disjoint",
	"[record]"
)
{
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
	fcppt::record::object<
		int_element
	>
	record1;

	typedef
	fcppt::record::object<
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

	CHECK(
		fcppt::record::get<
			int_label
		>(
			result
		)
		==
		42
	);

	CHECK(
		*fcppt::record::get<
			move_only_label
		>(
			result
		)
		==
		100
	);
}
