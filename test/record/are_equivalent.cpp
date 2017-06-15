//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/record/are_equivalent.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/variadic.hpp>


int
main()
{
	FCPPT_RECORD_MAKE_LABEL(
		label1
	);

	FCPPT_RECORD_MAKE_LABEL(
		label2
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			label1,
			int
		>,
		fcppt::record::element<
			label2,
			bool
		>
	>
	record1;

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			label2,
			bool
		>,
		fcppt::record::element<
			label1,
			int
		>
	>
	record2;

	static_assert(
		fcppt::record::are_equivalent<
			record1,
			record2
		>::value,
		""
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			label1,
			int
		>,
		fcppt::record::element<
			label2,
			int
		>
	>
	record3;

	static_assert(
		!fcppt::record::are_equivalent<
			record1,
			record3
		>::value,
		""
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			label1,
			int
		>
	>
	record4;

	static_assert(
		!fcppt::record::are_equivalent<
			record1,
			record4
		>::value,
		""
	);
}
