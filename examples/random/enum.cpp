//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_ref.hpp>
#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/enum/define_max_value.hpp>
#include <fcppt/random/variate.hpp>
#include <fcppt/random/distribution/basic.hpp>
#include <fcppt/random/distribution/parameters/make_uniform_enum.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/generator/minstd_rand.hpp>
#include <fcppt/random/generator/seed_from_chrono.hpp>
#include <fcppt/type_iso/enum.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>

namespace
{
// TODO(philipp): Make it possible to use std::uint8_t here.
// ![random_enum_definition]
enum class my_enum // NOLINT(performance-enum-size)
{
  value1,
  value2,
  value3
};
// ![random_enum_definition]

}
FCPPT_ENUM_DEFINE_MAX_VALUE(my_enum::value3)

int main()
{
  using generator_type = fcppt::random::generator::minstd_rand;

  generator_type generator(fcppt::random::generator::seed_from_chrono<generator_type::seed>());

  // ![random_enum_distribution]
  using uniform_enum = fcppt::random::distribution::basic<
      fcppt::random::distribution::parameters::uniform_int<my_enum>>;
  // ![random_enum_distribution]

  using variate = fcppt::random::variate<generator_type, uniform_enum>;

  // ![random_enum_parameters]
  variate rng(
      fcppt::make_ref(generator),
      uniform_enum(fcppt::random::distribution::parameters::make_uniform_enum<my_enum>()));
  // ![random_enum_parameters]

  my_enum const chosen(rng());

  std::cout << fcppt::cast::enum_to_underlying(chosen) << '\n';
}
