//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/record/all_disjoint.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	FCPPT_RECORD_MAKE_LABEL(
		label_1
	);

	FCPPT_RECORD_MAKE_LABEL(
		label_2
	);

	FCPPT_RECORD_MAKE_LABEL(
		label_3
	);

	typedef
	fcppt::record::element<
		label_1,
		int
	>
	element_1;

	typedef
	fcppt::record::element<
		label_2,
		int
	>
	element_2;

	typedef
	fcppt::record::element<
		label_3,
		int
	>
	element_3;

	static_assert(
		fcppt::record::all_disjoint<
			::brigand::list<
				fcppt::record::variadic<
					element_1
				>,
				fcppt::record::variadic<
					element_2
				>,
				fcppt::record::variadic<
					element_3
				>
			>
		>::value,
		""
	);

	static_assert(
		!fcppt::record::all_disjoint<
			::brigand::list<
				fcppt::record::variadic<
					element_1
				>,
				fcppt::record::variadic<
					element_1,
					element_2
				>,
				fcppt::record::variadic<
					element_3
				>
			>
		>::value,
		""
	);
}
