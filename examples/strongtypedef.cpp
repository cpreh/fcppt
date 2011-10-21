//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[strongtypedef_simple
#include <fcppt/strong_typedef.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>


namespace
{

struct distinct_type
{};

typedef fcppt::strong_typedef<
	int,
	distinct_type
> strong_int;

void
f(
	strong_int const i
)
{
	fcppt::io::cout()
		<< i
		<< FCPPT_TEXT('\n');
}

void
g()
{
	f(
		strong_int(42)
	);

	// f(42) won't work
}

}
//]

//[strongtypedef_macro
FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int2
);
//]

template class fcppt::strong_typedef<
	int,
	distinct_type
>;

int main()
{
	g();
}
