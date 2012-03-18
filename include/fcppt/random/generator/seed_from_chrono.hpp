//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_GENERATOR_SEED_FROM_CHRONO_HPP_INCLUDED
#define FCPPT_RANDOM_GENERATOR_SEED_FROM_CHRONO_HPP_INCLUDED

#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/chrono/high_resolution_clock.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace generator
{

template<
	typename Seed
>
typename boost::enable_if<
	boost::is_integral<
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
				fcppt::chrono::high_resolution_clock::now().time_since_epoch().count()
			)
		);
}

}
}
}

#endif
