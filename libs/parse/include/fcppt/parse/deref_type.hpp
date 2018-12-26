//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DEREF_TYPE_HPP_INCLUDED
#define FCPPT_PARSE_DEREF_TYPE_HPP_INCLUDED

#include <fcppt/parse/detail/deref_type.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Parser
>
using
deref_type
=
typename
fcppt::parse::detail::deref_type<
	Parser
>::type;

}
}

#endif
