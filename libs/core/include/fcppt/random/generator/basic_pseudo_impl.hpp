//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANDOM_GENERATOR_BASIC_PSEUDO_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_GENERATOR_BASIC_PSEUDO_IMPL_HPP_INCLUDED

#include <fcppt/random/generator/basic_pseudo_decl.hpp> // IWYU pragma: export

template <typename Generator>
inline fcppt::random::generator::basic_pseudo<Generator>::basic_pseudo(seed const _seed)
    : wrapped_(_seed.get())
{
}

template <typename Generator>
template <typename SeedSeq>
inline fcppt::random::generator::basic_pseudo<Generator>::basic_pseudo(SeedSeq &_seq)
    : wrapped_(_seq)
{
}

namespace fcppt::random::generator
{
template <typename Generator>
basic_pseudo<Generator>::~basic_pseudo() = default;
}

template <typename Generator>
inline typename fcppt::random::generator::basic_pseudo<Generator>::result_type
fcppt::random::generator::basic_pseudo<Generator>::operator()()
{
  return this->wrapped_();
}

template <typename Generator>
constexpr typename fcppt::random::generator::basic_pseudo<Generator>::result_type
fcppt::random::generator::basic_pseudo<Generator>::min()
{
  return wrapped::min();
}

template <typename Generator>
constexpr typename fcppt::random::generator::basic_pseudo<Generator>::result_type
fcppt::random::generator::basic_pseudo<Generator>::max()
{
  return wrapped::max();
}

#endif
