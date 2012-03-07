//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/mpl/append.hpp>
#include <fcppt/mpl/ceil_div.hpp>
#include <fcppt/mpl/contains_if.hpp>
#include <fcppt/mpl/implication.hpp>
#include <fcppt/mpl/index_of.hpp>
#include <fcppt/mpl/inner.hpp>
#include <fcppt/mpl/integral_cast.hpp>
#include <fcppt/mpl/max_value.hpp>
#include <fcppt/mpl/partial_sums.hpp>
#include <fcppt/mpl/print.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/mpl/vector/vector10_c.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{
namespace append
{
//! [mpl_append]
typedef
boost::mpl::vector2<
	int,
	float
>
vec1;

typedef
boost::mpl::vector2<
	char,
	double
>
vec2;

typedef
fcppt::mpl::append<
	vec1,
	vec2
>::type
vec3;

BOOST_STATIC_ASSERT((
	boost::mpl::equal<
		vec3,
		boost::mpl::vector4<
			int,
			float,
			char,
			double
		>
	>::value
));
//! [mpl_append]
}

namespace ceil_div
{
//! [mpl_ceil_div]
typedef
fcppt::mpl::ceil_div<
	unsigned,
	10u,
	3u
>::type
result;

BOOST_STATIC_ASSERT((
	boost::mpl::equal_to<
		result,
		boost::mpl::integral_c<
			unsigned,
			4u
		>
	>::value
));
//! [mpl_ceil_div]
}

namespace contains_if
{
//! [mpl_contains_if]
typedef
boost::mpl::vector2<
	float,
	unsigned
>
vec;

typedef
fcppt::mpl::contains_if<
	vec,
	boost::is_unsigned<
		boost::mpl::_1
	>
>::type
result;

BOOST_STATIC_ASSERT((
	boost::mpl::equal_to<
		result,
		boost::mpl::true_
	>::value
));
//! [mpl_contains_if]
}

namespace implication
{
//! [mpl_implication]
typedef
fcppt::mpl::implication<
	boost::mpl::false_,
	boost::mpl::true_
>::type
result;

BOOST_STATIC_ASSERT((
	boost::mpl::equal<
		result,
		boost::mpl::true_
	>::value
));
//! [mpl_implication]
}

namespace index_if
{
//! [mpl_index_of]
typedef
boost::mpl::vector3<
	float,
	int,
	double
>
vec;

typedef
fcppt::mpl::index_of<
	vec,
	int
>::type
result;

BOOST_STATIC_ASSERT((
	boost::mpl::equal_to<
		result,
		boost::mpl::integral_c<
			unsigned,
			1
		>
	>::value
));
//! [mpl_index_of]
}

namespace inner
{
//! [mpl_inner]
struct func
{
	typedef int type;
};

typedef
fcppt::mpl::inner<
	func
>::type
result;

BOOST_STATIC_ASSERT((
	boost::is_same<
		result,
		int
	>::value
));
//! [mpl_inner]
}

namespace integral_cast
{
//! [mpl_integral_cast]
typedef
boost::mpl::integral_c<
	int,
	2
> integral;

typedef
fcppt::mpl::integral_cast<
	unsigned,
	integral
>::type
result;

BOOST_STATIC_ASSERT((
	boost::is_same<
		result::value_type,
		unsigned
	>::value
	&&
	result::value
	==
	2u
));
//! [mpl_integral_cast]
}

namespace max_value
{
//! [mpl_max_value]
// Calculate the maximum size of all the types
typedef
boost::mpl::vector3<
	short,
	int,
	long
>
types;

typedef
fcppt::mpl::max_value<
	types,
	boost::mpl::sizeof_<
		boost::mpl::placeholders::_1
	>
>::type
result;

BOOST_STATIC_ASSERT((
	boost::mpl::equal_to<
		result,
		boost::mpl::sizeof_<
			long
		>
	>::value
));
//! [mpl_max_value]
}

namespace partial_sums
{
//! [mpl_partial_sums]
typedef
boost::mpl::vector3_c<
	int,
	3,
	4,
	5
>
vec;

typedef
fcppt::mpl::partial_sums<
	vec
>::type
result;

BOOST_STATIC_ASSERT((
	boost::mpl::equal<
		result,
		boost::mpl::vector4_c<
			int,
			0,
			3,
			7,
			12
		>
	>::value
));
//! [mpl_partial_sums]
}

namespace print
{
//! [mpl_print}
void
print_vec()
{
	typedef boost::mpl::vector3<
		int,
		float,
		double
	> vec;

	// prints (int, float, double) to cout
	fcppt::mpl::print<
		vec
	>(
		fcppt::io::cout()
	)
	<<
	FCPPT_TEXT('\n');

}
//! [mpl_print}
}

}

int
main()
{
	print::print_vec();
}
