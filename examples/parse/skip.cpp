//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/either/match.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/parse_string_error.hpp>
#include <fcppt/parse/parse_string_error_output.hpp>
#include <fcppt/parse/phrase_parse_string.hpp>
#include <fcppt/parse/uint.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/parse/skipper/literal.hpp>
#include <fcppt/parse/skipper/operators/repetition.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>

int main()
{
//![parse_uint]
  using uint_p = fcppt::parse::uint<unsigned>;
  auto const parser{uint_p{} >> uint_p{}};
//![parse_uint]

  auto const on_success([](fcppt::tuple::object<unsigned, unsigned> const &r) {
    std::cout << "The result is " << fcppt::tuple::get<0>(r) << ' ' << fcppt::tuple::get<1>(r)
              << ".\n";
  });

  auto const on_failure([](fcppt::parse::parse_string_error<char> const &e) { std::cerr << e << '\n'; });

//![parse_noskip]
  fcppt::either::match(
      fcppt::parse::parse_string(parser, std::string{"10 20"}), on_failure, on_success);
//![parse_noskip]

//![parse_skip]
  fcppt::either::match(
      fcppt::parse::phrase_parse_string(
          parser, std::string{"10 20"}, *fcppt::parse::skipper::literal{' '}),
      on_failure,
      on_success);
//![parse_skip]
}
