//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_GET_CHAR_HPP_INCLUDED
#define FCPPT_PARSE_GET_CHAR_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/io/get.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/state_impl.hpp>
#include <fcppt/parse/detail/check_bad.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
fcppt::optional::object<
	Ch
>
get_char(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state
)
{
	std::basic_istream<
		Ch
	> &stream{
		_state.get().stream()
	};

	fcppt::parse::detail::check_bad(
		stream
	);

	return
		fcppt::io::get(
			stream
		);
}

}
}

#endif
