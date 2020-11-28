//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_INDEX_AT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INDEX_AT_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{
template <typename Storage, typename SizeType>
inline fcppt::container::to_reference_type<Storage>
index_at(Storage &_storage, SizeType const _size)
{
  return _storage[_size];
}

}
}
}

#endif
