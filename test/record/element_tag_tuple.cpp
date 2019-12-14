//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/tag.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_tag_tuple.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
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
	my_record;

	typedef
	fcppt::record::element_tag_tuple<
		my_record
	>
	tag_tuple;

	static_assert(
		std::is_same_v<
			tag_tuple,
			std::tuple<
				fcppt::tag<
					int_element
				>,
				fcppt::tag<
					bool_element
				>
			>
		>
	);
}
