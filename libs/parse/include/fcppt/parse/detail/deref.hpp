//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_DEREF_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_DEREF_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

template<
	typename Parser
>
inline
Parser const &
deref(
	Parser const &_parser
)
{
	return
		_parser;
}

template<
	typename Parser
>
inline
Parser const &
deref(
	fcppt::reference<
		Parser const
	> const &_ref
)
{
	return
		fcppt::parse::detail::deref(
			_ref.get()
		);
}

}
}
}

#endif
