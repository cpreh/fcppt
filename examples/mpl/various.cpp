//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/mpl/append.hpp>
#include <fcppt/mpl/print.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
namespace append
{
//! [mpl_append]
typedef boost::mpl::vector2<
	int,
	float
> vec1;

typedef boost::mpl::vector2<
	char,
	double
> vec2;

// vec3 = (int, float, char, double)
typedef fcppt::mpl::append<
	vec1,
	vec2
>::type vec3;
//! [mpl_append]
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
	print_sequence<
		append::vec3
	>();
}
