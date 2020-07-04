//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_SCOPED_LINE_COUNTING_RDBUF_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_SCOPED_LINE_COUNTING_RDBUF_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/from_pointer.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/parse/detail/line_counting_rdbuf_impl.hpp>
#include <fcppt/parse/detail/scoped_line_counting_rdbuf_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <streambuf>
#include <fcppt/config/external_end.hpp>


template<
	typename Ch
>
fcppt::parse::detail::scoped_line_counting_rdbuf<
	Ch
>::scoped_line_counting_rdbuf(
	stream_ref const _stream
)
:
	stream_{
		_stream
	},
	old_buffer_{
		_stream.get().rdbuf()
	},
	buffer_{
		fcppt::optional::map(
			fcppt::optional::from_pointer(
				old_buffer_
			),
			[](
				fcppt::reference<
					std::basic_streambuf<
						Ch
					>
				> const _buf
			)
			{
				return
					fcppt::parse::detail::line_counting_rdbuf<
						Ch
					>(
						_buf
					);
			}
		)
	}
{
	fcppt::optional::maybe_void(
		this->buffer_,
		[
			this
		](
			fcppt::parse::detail::line_counting_rdbuf<
				Ch
			> &_buffer
		)
		{
			this->stream_.get().rdbuf(
				&_buffer
			);
		}
	);
}

template<
	typename Ch
>
fcppt::parse::detail::scoped_line_counting_rdbuf<
	Ch
>::~scoped_line_counting_rdbuf()
{
	this->stream_.get().rdbuf(
		this->old_buffer_
	);
}

#endif
