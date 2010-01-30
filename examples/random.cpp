//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/random/uniform.hpp>
#include <fcppt/random/inclusive_range.hpp>
#include <fcppt/random/last_exclusive_range.hpp>
#include <fcppt/random/actor/normalized.hpp>
#include <fcppt/random/actor/element.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <iostream>
#include <ostream>
#include <exception>
#include <cstdlib>

namespace
{

template<
	typename Rng
>
void print_values(
	Rng &rng
)
{
	for(unsigned i = 0; i < 100; ++i)
		fcppt::io::cout << rng() << FCPPT_TEXT(' ');

	fcppt::io::cout << FCPPT_TEXT('\n');
}

void
test_function()
{
	fcppt::io::cout << FCPPT_TEXT("test\n");
}

}

int main()
try
{
	fcppt::random::uniform<int> rng(
		fcppt::random::make_inclusive_range(
			0,
			10
		)
	);

	print_values(rng);

	fcppt::random::uniform<float> rngf(
		fcppt::random::make_inclusive_range(
			0.f,
			10.f
		)
	);

	print_values(rngf);

	fcppt::random::uniform<int> rngex(
		fcppt::random::make_last_exclusive_range(
			0,
			10
		)
	);

	print_values(rngex);

	fcppt::random::actor::normalized actor(
		fcppt::assign::make_container<
			fcppt::random::actor::container
		>(
			fcppt::random::actor::element(
				10.,
				test_function
			)
		)
	);

	actor();
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');
	
	return EXIT_FAILURE;
}
catch(
	std::exception const &e
)
{
	std::cerr
		<< e.what()
		<< '\n';
	
	return EXIT_FAILURE;
}
