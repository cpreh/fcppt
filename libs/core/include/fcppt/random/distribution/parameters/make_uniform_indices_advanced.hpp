//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_INDICES_ADVANCED_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_PARAMETERS_MAKE_UNIFORM_INDICES_ADVANCED_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/random/distribution/parameters/uniform_int.hpp>

namespace fcppt::random::distribution::parameters
{
template <typename Distribution, typename Container>
fcppt::optional::object<fcppt::random::distribution::parameters::
                            uniform_int<typename Container::size_type, Distribution>>
make_uniform_indices_advanced(Container const &_container)
{
  using param_type = fcppt::random::distribution::parameters::
      uniform_int<typename Container::size_type, Distribution>;

  using result_type = fcppt::optional::object<param_type>;

  return _container.empty()
             ? result_type()
             : result_type(param_type(
                   typename param_type::min(0U), typename param_type::max(_container.size() - 1U)));
}

}

#endif
