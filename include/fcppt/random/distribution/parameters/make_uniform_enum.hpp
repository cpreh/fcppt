//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_ENUM_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_ENUM_HPP_INCLUDED

#include <fcppt/random/distribution/parameters/make_uniform_enum_advanced.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>
#include <fcppt/random/distribution/parameters/uniform_int_wrapper_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{
namespace parameters
{

template<
	typename Enum
>
typename
boost::enable_if<
	std::is_enum<
		Enum
	>,
	fcppt::random::distribution::parameters::uniform_int<
		Enum
	>
>::type const
make_uniform_enum()
{
	return
		fcppt::random::distribution::parameters::make_uniform_enum_advanced<
			fcppt::random::distribution::parameters::uniform_int_wrapper,
			Enum
		>();
}

}
}
}
}

#endif
