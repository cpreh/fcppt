//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	static_assert(
		std::is_same<
			optional_int::value_type,
			int
		>::value,
		""
	);

	static_assert(
		std::is_same<
			optional_int::reference,
			int &
		>::value,
		""
	);

	static_assert(
		std::is_same<
			optional_int::const_reference,
			int const &
		>::value,
		""
	);

	typedef
	fcppt::optional::object<
		int &
	>
	optional_int_ref;

	static_assert(
		std::is_same<
			optional_int_ref::value_type,
			int
		>::value,
		""
	);

	static_assert(
		std::is_same<
			optional_int_ref::reference,
			int &
		>::value,
		""
	);

	typedef
	fcppt::optional::object<
		int const &
	>
	optional_const_int_ref;

	static_assert(
		std::is_same<
			optional_const_int_ref::value_type,
			int
		>::value,
		""
	);

	static_assert(
		std::is_same<
			optional_const_int_ref::reference,
			int const &
		>::value,
		""
	);
}
