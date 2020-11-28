//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANDOM_GENERATOR_MT19937_FWD_HPP_INCLUDED
#define FCPPT_RANDOM_GENERATOR_MT19937_FWD_HPP_INCLUDED

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
using mt19937 = fcppt::random::generator::basic_pseudo<std::mt19937>;

}
}
}

#endif
