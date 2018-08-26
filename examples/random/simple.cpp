//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/algorithm/repeat.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/random/variate.hpp>
#include <fcppt/random/distribution/basic.hpp>
#include <fcppt/random/distribution/parameters/normal.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/distribution/parameters/uniform_real.hpp>
#include <fcppt/random/generator/mt19937.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>


namespace
{

// ![random_print_values]
template<
	typename Rng
>
void
print_values(
	Rng &rng
)
{
	fcppt::algorithm::repeat(
		20u,
		[
			&rng
		]{
			fcppt::io::cout()
				<< rng()
				<< FCPPT_TEXT(' ');
		}
	);

	fcppt::io::cout()
		<< FCPPT_TEXT('\n');
}
// ![random_print_values]

}

int
main()
{
// ![random_generator]
	typedef fcppt::random::generator::mt19937 generator_type;

	generator_type generator(
		fcppt::random::generator::seed_from_chrono<
			generator_type::seed
		>()
	);
// ![random_generator]

	{
// ![random_uniform_int_distribution]
	typedef fcppt::random::distribution::basic<
		fcppt::random::distribution::parameters::uniform_int<
			int
		>
	> uniform_int;
// ![random_uniform_int_distribution]

// ![random_uniform_int]
	typedef fcppt::random::variate<
		generator_type,
		uniform_int
	> variate;

	variate rng(
		generator,
		uniform_int(
			uniform_int::param_type::min(
				0
			),
			uniform_int::param_type::max(
				10
			)
		)
	);

	print_values(
		rng
	);
// ![random_uniform_int]
	}

	{
	typedef fcppt::random::distribution::basic<
		fcppt::random::distribution::parameters::uniform_real<
			float
		>
	> uniform_real;

	typedef fcppt::random::variate<
		generator_type,
		uniform_real
	> variate;

	variate rng(
		generator,
		uniform_real(
			uniform_real::param_type::min(
				0.f
			),
			uniform_real::param_type::sup(
				10.f
			)
		)
	);

	print_values(
		rng
	);
	}

	{
// ![random_normal]
	typedef fcppt::random::distribution::basic<
		fcppt::random::distribution::parameters::normal<
			double
		>
	> normal;

	typedef fcppt::random::variate<
		generator_type,
		normal
	> variate;

	variate rng(
		generator,
		normal(
			normal::param_type::mean(
				0.
			),
			normal::param_type::stddev(
				5.
			)
		)
	);

	print_values(
		rng
	);
// ![random_normal]
	}
}
