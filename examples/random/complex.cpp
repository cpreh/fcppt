//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/repeat.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/random/variate.hpp>
#include <fcppt/random/distribution/basic.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/generator/minstd_rand.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>
#include <fcppt/type_iso/boost_units.hpp>
#include <fcppt/type_iso/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
//![random_complex_distribution]
	typedef
	boost::units::quantity<
		boost::units::si::length,
		int
	> meter;

	FCPPT_MAKE_STRONG_TYPEDEF(
		meter,
		radius
	);

	typedef
	fcppt::random::distribution::basic<
		fcppt::random::distribution::parameters::uniform_int<
			radius
		>
	>
	distribution;
//![random_complex_distribution]

	typedef
	fcppt::random::generator::minstd_rand
	generator_type;

	generator_type generator(
		fcppt::random::generator::seed_from_chrono<
			generator_type::seed
		>()
	);

	typedef
	fcppt::random::variate<
		generator_type,
		distribution
	>
	variate;

//![random_complex_variate]
	variate rng(
		generator,
		distribution(
			distribution::param_type::min(
				radius(
					0 * boost::units::si::meter
				)
			),
			distribution::param_type::max(
				radius(
					10 * boost::units::si::meter
				)
			)
		)
	);
//![random_complex_variate]

//![random_complex_output]
	fcppt::algorithm::repeat(
		10u,
		[
			&rng
		]{
			fcppt::io::cout()
				<< rng().get().value()
				<< FCPPT_TEXT(' ');
		}
	);
//![random_complex_output]

	fcppt::io::cout()
		<< FCPPT_TEXT('\n');

	typedef
	fcppt::random::distribution::basic<
		fcppt::random::distribution::parameters::uniform_int<
			meter
		>
	>
	meter_distribution;

	typedef
	fcppt::random::variate<
		generator_type,
		meter_distribution
	>
	meter_variate;

	meter_variate meter_rng(
		generator,
		meter_distribution(
			meter_distribution::param_type::min(
				0 * boost::units::si::meter
			),
			meter_distribution::param_type::max(
				10 * boost::units::si::meter
			)
		)
	);

	fcppt::algorithm::repeat(
		10u,
		[
			&meter_rng
		]{
			fcppt::io::cout()
				<< meter_rng().value()
				<< FCPPT_TEXT(' ');
		}
	);

	fcppt::io::cout()
		<< FCPPT_TEXT('\n');
}
