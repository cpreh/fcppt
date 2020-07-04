//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_LINE_COUNTING_RDBUF_DECL_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_LINE_COUNTING_RDBUF_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/line_number.hpp>
#include <fcppt/parse/detail/line_counting_rdbuf_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
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
class line_counting_rdbuf
:
	public
		std::basic_streambuf<
			Ch
		>
{
	FCPPT_NONMOVABLE(
		line_counting_rdbuf
	);
public:
	using
	base_type
	=
	std::basic_streambuf<
		Ch
	>;

	using
	streambuf_ref
	=
	fcppt::reference<
		base_type
	>;

	using
	traits_type
	=
	typename
	base_type::traits_type;

	explicit
	line_counting_rdbuf(
		streambuf_ref
	);

	~line_counting_rdbuf()
	override;

	void
	set_line(
		fcppt::parse::line_number
	);

	[[nodiscard]]
	fcppt::parse::line_number
	get_line() const;

	using
	int_type
	=
	typename
	base_type::int_type;

	[[nodiscard]]
	int_type
	underflow()
	override;

/*
	[[nodiscard]]
	int_type
	uflow()
	override;*/
private:
	streambuf_ref source_;

	Ch newline_;

	Ch buffer_;

	bool is_at_newline_;

	fcppt::parse::line_number line_;
};

}
}
}

#endif
