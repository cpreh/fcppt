//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DEFAULT_GENERATOR_HPP_INCLUDED
#define FCPPT_RANDOM_DEFAULT_GENERATOR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/random/linear_congruential.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace random
{

/// A convenience typedef for the default generator
typedef boost::minstd_rand default_generator;

}
}

#endif
