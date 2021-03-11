//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_IS_LAST_INDEX_HPP_INCLUDED
#define FCPPT_METAL_IS_LAST_INDEX_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace metal
{

/**
\brief Checks if an index is the last index of a list.
\ingroup fcpptmetal
\tparam List Must be a metal::list.
\tparam Index Must be a metal::number.
*/
template<typename List, typename Index>
using is_last_index = std::bool_constant<Index::value == ::metal::size<List>::value - ::metal::int_{1}>;

}
}

#endif
