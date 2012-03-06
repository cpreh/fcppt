//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/mpl/append.hpp>
#include <fcppt/mpl/ceil_div.hpp>
#include <fcppt/mpl/contains_if.hpp>
#include <fcppt/mpl/print.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector/vector10.hpp>
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

// vec3 = (int, float, char, double)
typedef
fcppt::mpl::append<
	vec1,
	vec2
>::type
vec3;
//! [mpl_append]
}

namespace ceil_div
{
//! [mpl_ceil_div]
// result = integral_c<unsigned, 4u>
typedef
fcppt::mpl::ceil_div<
	unsigned,
	10u,
	3u
>::type
result;
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

// result = true_
typedef
fcppt::mpl::contains_if<
	vec,
	boost::is_unsigned<
		boost::mpl::_1
	>
>::type
result;
//! [mpl_contains_if]
}

template<
	typename Type
>
void
print_sequence()
{
	fcppt::mpl::print<
		Type
	>(
		fcppt::io::cout()
	)
	<<
	FCPPT_TEXT('\n');

}

}

int
main()
{
	fcppt::io::cout()
		<< std::boolalpha;

	print_sequence<
		append::vec3
	>();

	fcppt::io::cout()
		<< ceil_div::result::value
		<< FCPPT_TEXT('\n');

	fcppt::io::cout()
		<< contains_if::result::value
		<< FCPPT_TEXT('\n');
}
