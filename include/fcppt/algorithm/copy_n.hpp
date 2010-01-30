//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_COPY_N_HPP_INCLUDED
#define FCPPT_ALGORITHM_COPY_N_HPP_INCLUDED

namespace fcppt
{
namespace algorithm
{

template<
	typename In,
	typename Out,
	typename Size
>
Out
copy_n(
	In beg,
	Size sz,
	Out out);

}
}

#include <fcppt/algorithm/detail/copy_n_impl.hpp>

#endif
