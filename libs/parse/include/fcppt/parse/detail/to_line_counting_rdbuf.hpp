//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_TO_LINE_COUNTING_RDBUF_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_TO_LINE_COUNTING_RDBUF_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/from_pointer.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/detail/line_counting_rdbuf_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <streambuf>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

template<
	typename Ch
>
fcppt::optional::object<
	fcppt::reference<
		fcppt::parse::detail::line_counting_rdbuf<
			Ch
		>
	>
>
to_line_counting_rdbuf(
	std::basic_istream<
		Ch
	> &_stream
)
{
	return
		fcppt::optional::bind(
			fcppt::optional::from_pointer(
				_stream.rdbuf()
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
					fcppt::cast::dynamic<
						fcppt::parse::detail::line_counting_rdbuf<
							Ch
						>
					>(
						_buf.get()
					);
			}
		);
}

}
}
}

#endif
