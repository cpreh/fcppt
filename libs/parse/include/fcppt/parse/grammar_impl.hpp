//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_GRAMMAR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_GRAMMAR_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/base_unique_ptr.hpp>
#include <fcppt/parse/grammar_decl.hpp>
#include <fcppt/parse/make_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Result, typename Ch, typename Skipper>
fcppt::parse::grammar<Result, Ch, Skipper>::grammar(
    fcppt::reference<base_type<Result> const> const _start, Skipper &&_skipper)
    : start_{_start}, skipper_{std::move(_skipper)}
{
}

template <typename Result, typename Ch, typename Skipper>
fcppt::parse::grammar<Result, Ch, Skipper>::~grammar<Result, Ch, Skipper>() = default;

template <typename Result, typename Ch, typename Skipper>
typename fcppt::parse::grammar<Result, Ch, Skipper>::template base_type<Result> const &
fcppt::parse::grammar<Result, Ch, Skipper>::start() const
{
  return this->start_.get();
}

template <typename Result, typename Ch, typename Skipper>
Skipper const &fcppt::parse::grammar<Result, Ch, Skipper>::skipper() const
{
  return this->skipper_;
}

template <typename Result, typename Ch, typename Skipper>
template <typename Parser>
typename fcppt::parse::grammar<Result, Ch, Skipper>::template base_type<
    fcppt::parse::result_of<Parser>>
fcppt::parse::grammar<Result, Ch, Skipper>::make_base(Parser &&_parser)
{
  return fcppt::parse::make_base<Ch, Skipper>(std::forward<Parser>(_parser));
}

#endif
