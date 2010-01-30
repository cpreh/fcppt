//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_IF_EXN_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_IF_EXN_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{

template<
	typename In,
	typename Comp
>
In
find_if_exn(
	In begin,
	In end,
	Comp const &);

}
}

#include <fcppt/algorithm/detail/find_if_exn_impl.hpp>

#endif
