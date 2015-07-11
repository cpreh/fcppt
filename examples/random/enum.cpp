//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/random/variate.hpp>
#include <fcppt/random/distribution/basic.hpp>
#include <fcppt/random/distribution/parameters/make_uniform_enum.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/generator/minstd_rand.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>
#include <fcppt/type_iso/enum.hpp>


namespace
{

// ![random_enum_definition]
enum class my_enum
{
	value1,
	value2,
	value3,
	fcppt_maximum = value3
};
// ![random_enum_definition]

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

// ![random_enum_distribution]
	typedef fcppt::random::distribution::basic<
		fcppt::random::distribution::parameters::uniform_int<
			my_enum
		>
	> uniform_enum;
// ![random_enum_distribution]

	typedef fcppt::random::variate<
		generator_type,
		uniform_enum
	> variate;

// ![random_enum_parameters]
	variate rng(
		generator,
		uniform_enum(
			fcppt::random::distribution::parameters::make_uniform_enum<
				my_enum
			>()
		)
	);
// ![random_enum_parameters]

	my_enum const chosen(
		rng()
	);

	fcppt::io::cout()
		<<
		fcppt::cast::enum_to_underlying(
			chosen
		)
		<<
		FCPPT_TEXT('\n');
}
