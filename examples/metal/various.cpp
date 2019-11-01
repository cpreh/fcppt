//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/brigand/equal_to.hpp>
#include <fcppt/brigand/list_c.hpp>
#include <fcppt/brigand/max_value.hpp>
#include <fcppt/brigand/partial_sums.hpp>
#include <fcppt/brigand/print.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/comparison/equal_to.hpp>
#include <brigand/functions/misc/sizeof.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <ostream>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{

namespace max_value
{
//! [brigand_max_value]
// Calculate the maximum size of all the types
typedef
brigand::list<
	short,
	int,
	long
>
types;

typedef
fcppt::brigand::max_value<
	brigand::transform<
		types,
		brigand::sizeof_<
			brigand::_1
		>
	>
>
result;

static_assert(
	brigand::equal_to<
		result,
		brigand::sizeof_<
			long
		>
	>::value,
	""
);
//! [brigand_max_value]
}

namespace partial_sums
{
//! [brigand_partial_sums]
typedef
fcppt::brigand::list_c<
	int,
	3,
	4,
	5
>
vec;

typedef
fcppt::brigand::partial_sums<
	vec
>
result;

static_assert(
	fcppt::brigand::equal_to<
		result,
		fcppt::brigand::list_c<
			int,
			0,
			3,
			7,
			12
		>
	>::value,
	""
);
//! [brigand_partial_sums]
}

namespace print
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wmissing-prototypes)

//! [brigand_print}
void
print_vec()
{
	typedef
	brigand::list<
		int,
		float,
		double
	>
	vec;

	// prints (int, float, double) to cout
	fcppt::brigand::print<
		vec
	>(
		fcppt::io::cout()
	)
	<<
	FCPPT_TEXT('\n');

}
//! [brigand_print}

FCPPT_PP_POP_WARNING
}

}

int
main()
{
	print::print_vec();
}
