//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_LINE_COUNTING_RDBUF_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_LINE_COUNTING_RDBUF_IMPL_HPP_INCLUDED

#include <fcppt/strong_typedef_arithmetic.hpp>
#include <fcppt/parse/line_number.hpp>
#include <fcppt/parse/detail/line_counting_rdbuf_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <locale>
#include <fcppt/config/external_end.hpp>


template<
	typename Ch
>
fcppt::parse::detail::line_counting_rdbuf<
	Ch
>::line_counting_rdbuf(
	streambuf_ref const _source
)
:
	source_{
		_source
	},
	newline_{
		std::use_facet<
			std::ctype<
				Ch
			>
		>(
			source_.get().getloc()
		).widen(
			'\n'
		)
	},
	buffer_{
		0
	},
	is_at_newline_{
		false
	},
	line_{
		1U
	}
{
}

template<
	typename Ch
>
fcppt::parse::detail::line_counting_rdbuf<
	Ch
>::~line_counting_rdbuf()
= default;

template<
	typename Ch
>
void
fcppt::parse::detail::line_counting_rdbuf<
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
fcppt::parse::detail::line_counting_rdbuf<
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
fcppt::parse::detail::line_counting_rdbuf<
	Ch
>::int_type
fcppt::parse::detail::line_counting_rdbuf<
	Ch
>::underflow()
{
	int_type const result{
		this->source_.get().sbumpc()
	};

	if(
		result
		!=
		traits_type::eof()
	)
	{
		this->buffer_ =
			traits_type::to_char_type(
				result
			);

		this->setg(
			&this->buffer_,
			&this->buffer_,
			std::next( // NOLINT(fuchsia-default-arguments-calls)
				&this->buffer_
			)
		);

		if(
			this->is_at_newline_
		)
		{
			++this->line_;
		}

		this->is_at_newline_ =
			this->buffer_
			==
			this->newline_;
	}

	return
		result;
}

/*
template<
	typename Ch
>
typename
fcppt::parse::detail::line_counting_rdbuf<
	Ch
>::int_type
fcppt::parse::detail::line_counting_rdbuf<
	Ch
>::uflow()
{
	int_type const result{
		this->underflow()
	};

	if(
		this->gptr()
		!=
		nullptr
		&&
		this->gptr()
		!=
		this->egptr()
	)
	{
		this->gbump(
			1
		);
	}

	return
		result;
}*/

#endif
