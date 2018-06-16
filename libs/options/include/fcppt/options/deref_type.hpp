//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DEREF_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONS_DEREF_TYPE_HPP_INCLUDED

#include <fcppt/options/detail/deref_type.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The dereferenced type of a parser.

\ingroup fcpptoptions

\tparam Parser A regular parser, an \link fcppt::reference\endlink to a parser or an \link fcppt::unique_ptr\endlink to a parser.
*/
template<
	typename Parser
>
using
deref_type
=
typename
fcppt::options::detail::deref_type<
	Parser
>::type;

}
}

#endif
