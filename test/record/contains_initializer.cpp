//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/detail/contains_initializer.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_RECORD_MAKE_LABEL(
	int_label
);

FCPPT_RECORD_MAKE_LABEL(
	bool_label
);

FCPPT_RECORD_MAKE_LABEL(
	float_label
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
fcppt::record::element<
	float_label,
	float
>
float_element;

template<
	typename... Args
>
void
test(
	Args &&...
)
{
	typedef
	brigand::list<
		fcppt::type_traits::remove_cv_ref_t<
			Args
		>...
	>
	args_type;

	static_assert(
		fcppt::record::detail::contains_initializer<
			args_type,
			int_element
		>::value,
		"Does not contain int element"
	);

	static_assert(
		fcppt::record::detail::contains_initializer<
			args_type,
			bool_element
		>::value,
		"Does not contain bool element"
	);

	static_assert(
		!fcppt::record::detail::contains_initializer<
			args_type,
			float_element
		>::value,
		"Does contain float element"
	);
}

}

int
main()
{
	test(
		bool_label{} = false,
		int_label{} = 0
	);
}
