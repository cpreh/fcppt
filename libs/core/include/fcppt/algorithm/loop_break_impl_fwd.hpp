//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LOOP_BREAK_IMPL_FWD_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_IMPL_FWD_HPP_INCLUDED


namespace fcppt
{
namespace algorithm
{

/**
\brief Customization point for ranges.

\ingroup fcpptalgorithm
*/
template<
	typename Range,
	typename Enable = void
>
struct loop_break_impl;

}
}

#endif
