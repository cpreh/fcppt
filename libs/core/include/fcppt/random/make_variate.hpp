//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANDOM_MAKE_VARIATE_HPP_INCLUDED
#define FCPPT_RANDOM_MAKE_VARIATE_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/random/variate_impl.hpp>

namespace fcppt::random
{
template <typename Generator, typename Distribution>
fcppt::random::variate<Generator, Distribution>
make_variate(fcppt::reference<Generator> const _generator, Distribution const &_distribution)
{
  return fcppt::random::variate<Generator, Distribution>(_generator, _distribution);
}

}

#endif
