//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_LOCATION_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_LOCATION_IMPL_HPP_INCLUDED

#include <fcppt/parse/column.hpp>
#include <fcppt/parse/line.hpp>
#include <fcppt/parse/location_decl.hpp>

inline fcppt::parse::location::location(
    fcppt::parse::line const _line, fcppt::parse::column const _column)
    : line_{_line}, column_{_column}
{
}

inline fcppt::parse::line fcppt::parse::location::line() const { return this->line_; }

inline fcppt::parse::line &fcppt::parse::location::line() { return this->line_; }

inline fcppt::parse::column fcppt::parse::location::column() const { return this->column_; }

inline fcppt::parse::column &fcppt::parse::location::column() { return this->column_; }

#endif
