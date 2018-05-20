//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/permute.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"record::permute"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		int_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		move_label
	);

	typedef
	fcppt::record::element<
		int_label,
		int
	>
	int_element;

	typedef
	fcppt::record::element<
		move_label,
		fcppt::unique_ptr<
			int
		>
	>
	move_element;

	typedef
	fcppt::record::variadic<
		int_element,
		move_element
	>
	result_record;

	typedef
	fcppt::record::variadic<
		move_element,
		int_element
	>
	arg_record;

	result_record const result{
		fcppt::record::permute<
			result_record
		>(
			arg_record{
				int_label{} =
					42,
				move_label{} =
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
			move_label
		>(
			result
		)
		==
		100
	);
}
