//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_GENERATOR_MINSTD_RAND_FWD_HPP_INCLUDED
#define FCPPT_RANDOM_GENERATOR_MINSTD_RAND_FWD_HPP_INCLUDED

#include <fcppt/random/generator/basic_pseudo_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <random>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace generator
{

typedef fcppt::random::generator::basic_pseudo<
	std::minstd_rand
> minstd_rand;

}
}
}

#endif
