//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/record/comparison.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"record comparison",
	"[record]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		int_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		bool_label
	);

	typedef
	fcppt::record::element<
		int_label,
		int
	>
	int_element;

	typedef
	fcppt::record::element<
		bool_label,
		bool
	>
	bool_element;

	typedef
	fcppt::record::object<
		int_element,
		bool_element
	>
	record1;

	typedef
	fcppt::record::object<
		bool_element,
		int_element
	>
	record2;

	CHECK(
		record1(
			int_label{} = 42,
			bool_label{} = false
		)
		==
		record2(
			int_label{} = 42,
			bool_label{} = false
		)
	);

	CHECK(
		record1(
			int_label{} = 42,
			bool_label{} = false
		)
		==
		record1(
			int_label{} = 42,
			bool_label{} = false
		)
	);

	CHECK(
		record1(
			int_label{} = 42,
			bool_label{} = false
		)
		!=
		record1(
			int_label{} = 42,
			bool_label{} = true
		)
	);
}
