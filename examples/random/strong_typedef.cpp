//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/random/variate.hpp>
#include <fcppt/random/distribution/basic.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/generator/minstd_rand.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>
#include <fcppt/type_iso/strong_typedef.hpp>


int
main()
{
//![random_strong_typedef_distribution]
	FCPPT_MAKE_STRONG_TYPEDEF(
		int,
		my_type
	);

	typedef
	fcppt::random::distribution::basic<
		fcppt::random::distribution::parameters::uniform_int<
			my_type
		>
	>
	distribution;
//![random_strong_typedef_distribution]

	typedef
	fcppt::random::generator::minstd_rand
	generator_type;

	generator_type generator(
		fcppt::random::generator::seed_from_chrono<
			generator_type::seed
		>()
	);

	typedef fcppt::random::variate<
		generator_type,
		distribution
	> variate;

//![random_strong_typedef_variate]
	variate rng(
		generator,
		distribution(
			distribution::param_type::min(
				my_type(
					0
				)
			),
			distribution::param_type::max(
				my_type(
					10
				)
			)
		)
	);
//![random_strong_typedef_variate]

//![random_strong_typedef_output]
	for(
		unsigned i = 0;
		i < 10;
		++i
	)
		fcppt::io::cout()
			// Outputs objects of type my_type
			<< rng()
			<< FCPPT_TEXT(' ');
//![random_strong_typedef_output]

	fcppt::io::cout()
		<< FCPPT_TEXT('\n');
}
