//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/cout.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/text.hpp>

FCPPT_MAKE_STRONG_TYPEDEF(int, strong_int)

int main()
{
	strong_int i(42);

	fcppt::io::cout
		<< i
		<< FCPPT_TEXT('\n');
}
