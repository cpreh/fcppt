//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_STREAM_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_STREAM_DECL_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/position_fwd.hpp>
#include <fcppt/nonmovable.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
class basic_stream
{
	FCPPT_NONMOVABLE(
		basic_stream
	);
public:
	basic_stream();

	virtual
	~basic_stream() = 0;

	[[nodiscard]]
	virtual
	fcppt::optional::object<
		Ch
	>
	get_char() = 0;

	[[nodiscard]]
	virtual
	fcppt::parse::position<
		Ch
	>
	get_position() const = 0;

	virtual
	void
	set_position(
		fcppt::parse::position<
			Ch
		> const &
	) = 0;
};

}
}

#endif
