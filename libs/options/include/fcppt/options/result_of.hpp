//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_RESULT_OF_HPP_INCLUDED
#define FCPPT_OPTIONS_RESULT_OF_HPP_INCLUDED

#include <fcppt/options/detail/result_of.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The result of a parser type.

\ingroup fcpptoptions

\tparam Parser Either a parser or an \link fcppt::options::base_unique_ptr\endlink.
*/
template<
	typename Parser
>
using
result_of
=
typename
fcppt::options::detail::result_of<
	Parser
>::type;

}
}

#endif
