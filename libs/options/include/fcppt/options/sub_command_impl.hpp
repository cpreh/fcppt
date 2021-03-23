//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_SUB_COMMAND_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_SUB_COMMAND_IMPL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/sub_command_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Tag, typename Parser>
fcppt::options::sub_command<Tag, Parser>::sub_command(
    fcppt::string &&_name, Parser &&_parser, fcppt::options::optional_help_text &&_help_text)
    : name_{std::move(_name)}, parser_{std::move(_parser)}, help_text_{std::move(_help_text)}
{
}

template <typename Tag, typename Parser>
fcppt::string const &fcppt::options::sub_command<Tag, Parser>::name() const
{
  return name_;
}

template <typename Tag, typename Parser>
Parser const &fcppt::options::sub_command<Tag, Parser>::parser() const
{
  return parser_;
}

template <typename Tag, typename Parser>
fcppt::options::optional_help_text const &
fcppt::options::sub_command<Tag, Parser>::help_text() const
{
  return help_text_;
}

#endif
