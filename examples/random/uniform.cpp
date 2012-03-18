//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/random/variate.hpp>
#include <fcppt/random/distribution/normal.hpp>
#include <fcppt/random/distribution/uniform_int.hpp>
#include <fcppt/random/distribution/uniform_real.hpp>
#include <fcppt/random/generator/minstd_rand.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>


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
		fcppt::io::cout()
			<< rng()
			<< FCPPT_TEXT(' ');

	fcppt::io::cout()
		<< FCPPT_TEXT('\n');
}

}

int
main()
{
	typedef fcppt::random::generator::minstd_rand generator_type;

	generator_type generator(
		fcppt::random::generator::seed_from_chrono<
			generator_type::seed
		>()
	);

	{
		typedef fcppt::random::distribution::uniform_int<
			int
		> uniform_int;

		typedef fcppt::random::variate<
			generator_type,
			uniform_int
		> variate;

		variate rng(
			generator,
			uniform_int(
				uniform_int::min(
					0
				),
				uniform_int::max(
					10
				)
			)
		);

		print_values(
			rng
		);
	}

	{
		typedef fcppt::random::distribution::uniform_real<
			float
		> uniform_real;

		typedef fcppt::random::variate<
			generator_type,
			uniform_real
		> variate;

		variate rng(
			generator,
			uniform_real(
				uniform_real::min(
					0.f
				),
				uniform_real::sup(
					10.f
				)
			)
		);

		print_values(
			rng
		);
	}

	{
		typedef fcppt::random::distribution::normal<
			double
		> normal;

		typedef fcppt::random::variate<
			generator_type,
			normal
		> variate;

		variate rng(
			generator,
			normal(
				normal::mean(
					0.
				),
				normal::sigma(
					5.
				)
			)
		);

		print_values(
			rng
		);
	}
}
