//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_fatal.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/operators/alternative.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{
void on_failure(fcppt::parse::error<char> const &e){ std::cerr << e << '\n'; }
void on_success(fcppt::unit) { std::cout << "Success\n"; }

void f()
{
//![parsers1]
  using lit = fcppt::parse::literal;
  auto const a{lit{'{'} >> lit{'}'}};
  auto const b{lit{'['} >> lit{']'}};
  auto const p{fcppt::make_cref(a) | fcppt::make_cref(b)};
//![parsers1]
  fcppt::either::match(fcppt::parse::parse_string(p, std::string{"{]"}), on_failure, on_success);
}

void g()
{
//![parsers2]
  using lit = fcppt::parse::literal;
  auto const a{lit{'{'} >> fcppt::parse::make_fatal(lit{'}'})};
  auto const b{lit{'['} >> lit{']'}};
  auto const p{fcppt::make_cref(a) | fcppt::make_cref(b)};
//![parsers2]
fcppt::either::match(fcppt::parse::parse_string(p, std::string{"{]"}), on_failure, on_success);
}
}

int main()
{
  f();
  g();
}
