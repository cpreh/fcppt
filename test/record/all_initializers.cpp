//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/detail/all_initializers.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace
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

template<
	bool Expected,
	typename... Args
>
void
test(
	Args &&...
)
{
	typedef
	metal::list<
		bool_element,
		int_element
	>
	elements;

	typedef
	metal::list<
		fcppt::type_traits::remove_cv_ref_t<
			Args
		>...
	>
	args_type;

	static_assert(
		fcppt::record::detail::all_initializers<
			elements,
			args_type
		>::value
		==
		Expected,
		"Broken all_initializers"
	);
}

}

int
main()
{
	test<
		true
	>(
		bool_label{} = false,
		int_label{} = 0
	);

	test<
		false
	>(
		bool_label{} = false
	);

	test<
		false
	>(
		int_label{} = 0
	);

	test<
		false
	>();
}
