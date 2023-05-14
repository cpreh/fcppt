//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_GRAMMAR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_GRAMMAR_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/base_unique_ptr.hpp>
#include <fcppt/parse/grammar_fwd.hpp>
#include <fcppt/parse/result_of.hpp>

namespace fcppt::parse
{
/**
\brief Base class for grammars.

\ingroup fcpptparse

Usually, parsers are mutually recursive. For example, in JSON, the parser for
objects depends on the parser for values, and the parser for values depends on
the parser for objects. To implement this, it is necessary to have both parsers
as elements of a struct, so that they can refer to each other in the
constructor. We also refer to these parsers as nonterminals. A struct that
"collects" nonterminals and "connects" them in its constructor, is called a
"grammar", similar to what a context-free grammar does in computer science.

The base class for grammars gets a special parser, called the start parser.
It also gets a skipper, which is shared by all nonterminals.
*/
template <typename Result, typename Ch, typename Skipper>
class grammar
{
  FCPPT_NONMOVABLE(grammar);

public:
  using grammar_base = grammar;

  using result_type = Result;

  using char_type = Ch;

  template <typename Type>
  using base_type = fcppt::parse::base_unique_ptr<Type, Ch, Skipper>;

  grammar(fcppt::reference<base_type<Result> const>, Skipper &&);

  ~grammar();

  [[nodiscard]] base_type<Result> const &start() const;

  [[nodiscard]] Skipper const &skipper() const;

  template <typename Parser>
  [[nodiscard]] static base_type<fcppt::parse::result_of<Parser>> make_base(Parser &&);

private:
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
  fcppt::reference<base_type<Result> const> const start_;

  // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
  Skipper const skipper_;
};

}

#endif
