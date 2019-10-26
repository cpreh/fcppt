//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_SET_INTERSECTION_HPP_INCLUDED
#define FCPPT_METAL_SET_INTERSECTION_HPP_INCLUDED

#include <fcppt/metal/set/contains.hpp>
#include <fcppt/metal/set/insert_relaxed.hpp>
#include <fcppt/metal/set/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/always.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/accumulate.hpp>
#include <metal/number/if.hpp>
#include <metal/pair/first.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{
namespace set
{

/**
\brief The intersection of two sets.

\ingroup fcpptmetal

The result contains every element that is both in \a Set1 and \a Set2.

\tparam Set1 Must be a metal set.

\tparam Set2 Must be a metal set.
*/
template<
	typename Set1,
	typename Set2
>
using
intersection
=
::metal::accumulate<
	::metal::bind<
		::metal::lambda<
			::metal::if_
		>,
		::metal::bind<
			::metal::lambda<
				fcppt::metal::set::contains
			>,
			::metal::always<
				Set2
			>,
			::metal::bind<
				::metal::lambda<
					::metal::first
				>,
				::metal::_2
			>
		>,
		::metal::bind<
			::metal::lambda<
				fcppt::metal::set::insert_relaxed
			>,
			::metal::_1,
			::metal::bind<
				::metal::lambda<
					::metal::first
				>,
				::metal::_2
			>
		>,
		::metal::_1
	>,
	fcppt::metal::set::make<>,
	Set1
>;

}
}
}

#endif
