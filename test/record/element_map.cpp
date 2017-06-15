//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/record/element.hpp>
#include <fcppt/record/element_map.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/at.hpp>
#include <fcppt/config/external_end.hpp>


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
		>,
		fcppt::record::element<
			bool_label,
			bool
		>
	>
	my_record;

	typedef
	fcppt::record::element_map<
		my_record
	>
	element_map;

	static_assert(
		std::is_same<
			boost::mpl::at<
				element_map,
				int_label
			>::type,
			int
		>::value,
		""
	);

	static_assert(
		std::is_same<
			boost::mpl::at<
				element_map,
				bool_label
			>::type,
			bool
		>::value,
		""
	);
}
