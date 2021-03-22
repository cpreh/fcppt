//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_cref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/recursive.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/parse/char_set.hpp>
#include <fcppt/parse/construct.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/grammar.hpp>
#include <fcppt/parse/grammar_parse_string.hpp>
#include <fcppt/parse/list.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_recursive.hpp>
#include <fcppt/parse/operators/repetition_plus.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
#include <fcppt/tuple/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

//![list_decl]
struct list;
using entry = fcppt::tuple::object<std::string, fcppt::recursive<list>>;
struct list { std::vector<entry> elements; };
//![list_decl]

//![grammar_decl]
using grammar_base = fcppt::parse::grammar<list, char, fcppt::parse::skipper::epsilon>;
class grammar : public grammar_base
{
  FCPPT_NONMOVABLE(grammar);
public:
  grammar();
  ~grammar() = default;

private:
  grammar_base::base_type<list> list_p;
  grammar_base::base_type<entry> entry_p;
};
//![grammar_decl]

//![grammar_impl]
grammar::grammar()
    : grammar_base{fcppt::make_cref(list_p), fcppt::parse::skipper::epsilon{}},
      list_p{grammar_base::make_base(fcppt::parse::construct<list>(fcppt::parse::list{
          fcppt::parse::literal{'{'},
          fcppt::make_cref(entry_p),
          fcppt::parse::literal{','},
          fcppt::parse::literal{'}'}}))},
      entry_p{grammar_base::make_base(
          +fcppt::parse::char_set{'a', 'b', 'c'} >> fcppt::parse::literal{'='} >>
          fcppt::parse::make_recursive(fcppt::make_cref(list_p)))}
{
}
//![grammar_impl]

int main()
{
  auto const on_failure{
      [](fcppt::parse::error<char> const &_error) { std::cerr << _error << '\n'; }};
  auto const on_success{[](list const &_result) { std::cout << _result.elements.size() << '\n'; }};

//![parse]
  fcppt::either::match(
      fcppt::parse::grammar_parse_string(std::string{"{ab={c={}},b={}}"},grammar{}),
      on_failure,
      on_success);
//![parse]
}
