//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/brigand/ceil_div.hpp>
#include <fcppt/brigand/equal_to.hpp>
#include <fcppt/brigand/implication.hpp>
#include <fcppt/brigand/integral_cast.hpp>
#include <fcppt/brigand/list_c.hpp>
#include <fcppt/brigand/max_value.hpp>
#include <fcppt/brigand/partial_sums.hpp>
#include <fcppt/brigand/print.hpp>
#include <fcppt/cast/to_unsigned_fun.hpp>
#include <fcppt/io/cout.hpp>
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

namespace ceil_div
{
//! [brigand_ceil_div]
typedef
fcppt::brigand::ceil_div<
	unsigned,
	10u,
	3u
>
result;

static_assert(
	std::is_same<
		result,
		std::integral_constant<
			unsigned,
			4u
		>
	>::value,
	""
);
//! [brigand_ceil_div]
}

namespace implication
{
//! [brigand_implication]
typedef
fcppt::brigand::implication<
	std::false_type,
	std::true_type
>
result;

static_assert(
	brigand::equal_to<
		result,
		std::true_type
	>::value,
	""
);
//! [brigand_implication]
}

namespace integral_cast
{
//! [brigand_integral_cast]
typedef
std::integral_constant<
	int,
	2
> integral;

typedef
fcppt::brigand::integral_cast<
	unsigned,
	fcppt::cast::to_unsigned_fun,
	integral
>::type
result;

static_assert(
	std::is_same<
		result::value_type,
		unsigned
	>::value
	&&
	result::value
	==
	2u,
	""
);
//! [brigand_integral_cast]
}

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
}

}

int
main()
{
	print::print_vec();
}
