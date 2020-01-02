//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_CONTEXT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_CONTEXT_IMPL_HPP_INCLUDED

#include <fcppt/optional/reference.hpp>
#include <fcppt/parse/context_decl.hpp>


template<
	typename Skipper
>
fcppt::parse::context<
	Skipper
>::context(
	skipper_ref const _skipper
)
:
	skipper_{
		_skipper
	}
{
}

template<
	typename Skipper
>
typename
fcppt::parse::context<
	Skipper
>::skipper_ref
fcppt::parse::context<
	Skipper
>::skipper() const
{
	return
		this->skipper_;
}

#endif
