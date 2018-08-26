//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/record/are_disjoint.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/variadic.hpp>


int
main()
{
	FCPPT_RECORD_MAKE_LABEL(
		int_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		bool_label
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			int_label,
			int
		>
	>
	record1;

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			bool_label,
			bool
		>
	>
	record2;

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			int_label,
			int
		>,
		fcppt::record::element<
			bool_label,
			bool
		>
	>
	record3;

	static_assert(
		fcppt::record::are_disjoint<
			record1,
			record2
		>::value,
		""
	);

	static_assert(
		!fcppt::record::are_disjoint<
			record1,
			record3
		>::value,
		""
	);

	static_assert(
		!fcppt::record::are_disjoint<
			record2,
			record3
		>::value,
		""
	);
}
