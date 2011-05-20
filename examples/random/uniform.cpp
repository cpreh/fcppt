//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[randomuniform
#include <fcppt/random/make_inclusive_range.hpp>
#include <fcppt/random/make_last_exclusive_range.hpp>
#include <fcppt/random/uniform.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

namespace
{

// helper function used to draw 20 values out of a generator
template<
	typename Rng
>
void
print_values(
	Rng &rng
)
{
	for(
		unsigned i = 0;
		i < 20;
		++i
	)
		fcppt::io::cout
			<< rng()
			<< FCPPT_TEXT(' ');

	fcppt::io::cout
		<< FCPPT_TEXT('\n');
}

}

int main()
{
	{
		// create a uniform inclusive distribution [0, 10]
		fcppt::random::uniform<int> rng(
			fcppt::random::make_inclusive_range(
				0,
				10
			)
		);

		print_values(
			rng
		);
	}

	{
		// create a uniform inclusive distribution [0, 10] over float instead
		fcppt::random::uniform<float> rngf(
			fcppt::random::make_inclusive_range(
				0.f,
				10.f
			)
		);

		print_values(
			rngf
		);
	}

	{
		// create a uniform exclusive distribution [0, 10)
		fcppt::random::uniform<int> rngex(
			fcppt::random::make_last_exclusive_range(
				0,
				10
			)
		);

		print_values(
			rngex
		);
	}
}
//]
