//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_LINE_COUNTING_RDBUF_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_LINE_COUNTING_RDBUF_IMPL_HPP_INCLUDED

#include <fcppt/string_literal.hpp>
#include <fcppt/strong_typedef_arithmetic.hpp>
#include <fcppt/parse/line_counting_rdbuf_decl.hpp>
#include <fcppt/parse/line_number.hpp>


template<
	typename Ch
>
fcppt::parse::line_counting_rdbuf<
	Ch
>::line_counting_rdbuf(
	streambuf_ref const _source
)
:
	source_{
		_source
	},
	line_{
		1U
	}
{
}

template<
	typename Ch
>
fcppt::parse::line_counting_rdbuf<
	Ch
>::~line_counting_rdbuf()
= default;

template<
	typename Ch
>
void
fcppt::parse::line_counting_rdbuf<
	Ch
>::set_line(
	fcppt::parse::line_number const _line
)
{
	this->line_ =
		_line;
}

template<
	typename Ch
>
fcppt::parse::line_number
fcppt::parse::line_counting_rdbuf<
	Ch
>::get_line() const
{
	return
		this->line_;
}

template<
	typename Ch
>
typename
fcppt::parse::line_counting_rdbuf<
	Ch
>::int_type
fcppt::parse::line_counting_rdbuf<
	Ch
>::uflow()
{
	int_type const result{
		source_.get().uflow()
	};

	if(
		result
		==
		FCPPT_STRING_LITERAL(
			Ch,
			'\n'
		)
	)
	{
		++this->line_;
	}

	return
		result;
}

#endif
