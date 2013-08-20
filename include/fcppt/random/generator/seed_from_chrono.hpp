//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_GENERATOR_SEED_FROM_CHRONO_HPP_INCLUDED
#define FCPPT_RANDOM_GENERATOR_SEED_FROM_CHRONO_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <chrono>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace generator
{

/**
\brief Creates a seed from a chrono clock

\ingroup fcpptrandom

Creates a seed of type \a Seed from a chrono clock.

\tparam Seed The seed type of a pseudo random number generator. Its value_type
must be an integral type.

\note If you use this function, you must link to boost.chrono

\return The seed
*/
template<
	typename Seed
>
typename boost::enable_if<
	std::is_integral<
		typename Seed::value_type
	>,
	Seed
>::type const
seed_from_chrono()
{
	return
		Seed(
			static_cast<
				typename Seed::value_type
			>(
				std::chrono::high_resolution_clock::now().time_since_epoch().count()
			)
		);
}

}
}
}

#endif
