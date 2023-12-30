//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANGE_HASH_IMPL_HPP_INCLUDED
#define FCPPT_RANGE_HASH_IMPL_HPP_INCLUDED

#include <fcppt/hash.hpp>
#include <fcppt/hash_combine.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/range/hash_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

template <typename Type>
inline std::size_t fcppt::range::hash<Type>::operator()(Type const &_value) const
{
  return fcppt::algorithm::fold(
      _value, std::size_t{0U}, [](auto const &_element, std::size_t const _cur) -> std::size_t {
        return fcppt::hash_combine(_cur, fcppt::hash(_element));
      });
}

#endif
