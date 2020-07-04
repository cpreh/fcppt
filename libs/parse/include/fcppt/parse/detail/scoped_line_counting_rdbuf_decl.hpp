//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_SCOPED_LINE_COUNTING_RDBUF_DECL_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_SCOPED_LINE_COUNTING_RDBUF_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_decl.hpp>
#include <fcppt/unique_ptr_decl.hpp>
#include <fcppt/optional/object_decl.hpp>
#include <fcppt/parse/detail/line_counting_rdbuf_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
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
class scoped_line_counting_rdbuf
{
	FCPPT_NONMOVABLE(
		scoped_line_counting_rdbuf
	);
public:
	using
	stream_ref
	=
	fcppt::reference<
		std::basic_ios<
			Ch
		>
	>;

	explicit
	scoped_line_counting_rdbuf(
		stream_ref
	);

	~scoped_line_counting_rdbuf();
private:
	stream_ref const stream_;

	std::basic_streambuf<
		Ch
	> *old_buffer_;

	fcppt::optional::object<
		fcppt::unique_ptr<
			fcppt::parse::detail::line_counting_rdbuf<
				Ch
			>
		>
	> buffer_;
};

}
}
}

#endif
