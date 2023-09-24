//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/strong_typedef.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/algorithm/repeat.hpp>
#include <fcppt/random/variate.hpp>
#include <fcppt/random/distribution/basic.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/generator/minstd_rand.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>
#include <fcppt/type_iso/strong_typedef.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  //![random_strong_typedef_distribution]
  FCPPT_DECLARE_STRONG_TYPEDEF(int, my_type);

  using distribution = fcppt::random::distribution::basic<
      fcppt::random::distribution::parameters::uniform_int<my_type>>;
  //![random_strong_typedef_distribution]

  using generator_type = fcppt::random::generator::minstd_rand;

  generator_type generator(fcppt::random::generator::seed_from_chrono<generator_type::seed>());

  using variate = fcppt::random::variate<generator_type, distribution>;

  //![random_strong_typedef_variate]
  variate rng(
      fcppt::make_ref(generator),
      distribution(
          distribution::param_type::min(my_type(0)), distribution::param_type::max(my_type(10))));
  //![random_strong_typedef_variate]

  //![random_strong_typedef_output]
  fcppt::algorithm::repeat(10U, [&rng] { std::cout << rng() << ' '; });
  //![random_strong_typedef_output]

  std::cout << '\n';
}
