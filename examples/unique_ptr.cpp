//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

namespace
{

typedef fcppt::unique_ptr<
	int
> int_ptr;

int_ptr
int_ptr_factory()
{
	return 
		fcppt::make_unique_ptr<
			int
		>(
			42
		);
}

void
int_ptr_arg(
	int_ptr ptr
)
{
	fcppt::io::cout
		<< *ptr
		<< FCPPT_TEXT('\n');
}

void
test()
{
	int_ptr_arg(
		int_ptr_factory()
	);
}

}

int main()
{
}
