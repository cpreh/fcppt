//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_DEREF_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_DEREF_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/base_fwd.hpp>
#include <fcppt/parse/base_unique_ptr_fwd.hpp>


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
	typename Result,
	typename Ch,
	typename Skipper
>
inline
fcppt::parse::base<
	Result,
	Ch,
	Skipper
> const &
deref(
	fcppt::parse::base_unique_ptr<
		Result,
		Ch,
		Skipper
	> const &_ptr
)
{
	return
		*_ptr;
}

template<
	typename Parser
>
inline
auto
deref(
	fcppt::reference<
		Parser const
	> const &_ref
)
->
decltype(
	fcppt::parse::detail::deref(
		_ref.get()
	)
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
