//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_traits/generate_has_type.hpp>


namespace
{

FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE(
	size_type
);

struct foo
{
};

struct bar
{
	typedef
	int
	size_type;
};

}

int
main()
{
	static_assert(
		!has_size_type<
			foo
		>::value,
		""
	);

	static_assert(
		has_size_type<
			bar
		>::value,
		""
	);
}

