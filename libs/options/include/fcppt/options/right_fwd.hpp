//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_RIGHT_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_RIGHT_FWD_HPP_INCLUDED

#include <fcppt/options/detail/right_tag.hpp>
#include <fcppt/strong_typedef_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The right result type of a sum parser.

\ingroup fcpptoptions
*/
template<
	typename Type
>
using
right
=
fcppt::strong_typedef<
	Type,
	fcppt::options::detail::right_tag
>;

}
}

#endif
