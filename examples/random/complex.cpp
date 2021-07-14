//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/algorithm/repeat.hpp>
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
#include <iostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  //![random_complex_distribution]
  using meter = boost::units::quantity<boost::units::si::length, int>;

  FCPPT_MAKE_STRONG_TYPEDEF(meter, radius);

  using distribution = fcppt::random::distribution::basic<
      fcppt::random::distribution::parameters::uniform_int<radius>>;
  //![random_complex_distribution]

  using generator_type = fcppt::random::generator::minstd_rand;

  generator_type generator(fcppt::random::generator::seed_from_chrono<generator_type::seed>());

  using variate = fcppt::random::variate<generator_type, distribution>;

  //![random_complex_variate]
  variate rng(
      fcppt::make_ref(generator),
      distribution(
          distribution::param_type::min(radius(0 * boost::units::si::meter)),
          distribution::param_type::max(radius(10 * boost::units::si::meter))));
  //![random_complex_variate]

  //![random_complex_output]
  fcppt::algorithm::repeat(10U, [&rng] { std::cout << rng().get().value() << ' '; });
  //![random_complex_output]

  std::cout << '\n';

  using meter_distribution = fcppt::random::distribution::basic<
      fcppt::random::distribution::parameters::uniform_int<meter>>;

  using meter_variate = fcppt::random::variate<generator_type, meter_distribution>;

  meter_variate meter_rng(
      fcppt::make_ref(generator),
      meter_distribution(
          meter_distribution::param_type::min(0 * boost::units::si::meter),
          meter_distribution::param_type::max(10 * boost::units::si::meter)));

  fcppt::algorithm::repeat(10U, [&meter_rng] { std::cout << meter_rng().value() << ' '; });

  std::cout << '\n';
}
