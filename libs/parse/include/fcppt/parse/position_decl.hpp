//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_POSITION_DECL_HPP_INCLUDED
#define FCPPT_PARSE_POSITION_DECL_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/line_number.hpp>
#include <fcppt/parse/position_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
class position
{
public:
	using
	pos_type
	=
	typename
	std::basic_istream<
		Ch
	>::pos_type;

	using
	optional_line_number
	=
	fcppt::optional::object<
		fcppt::parse::line_number
	>;

	position(
		pos_type,
		optional_line_number const &
	);

	[[nodiscard]]
	pos_type const &
	pos() const;

	[[nodiscard]]
	optional_line_number const &
	line() const;
private:
	pos_type pos_;

	optional_line_number line_;
};

}
}

#endif
