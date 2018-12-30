//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_RESULT_FWD_HPP_INCLUDED
#define FCPPT_PARSE_RESULT_FWD_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename T
>
using
result
=
fcppt::optional::object<
	T
>;

}
}

#endif