//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_ALL_DISJOINT_HPP_INCLUDED
#define FCPPT_RECORD_ALL_DISJOINT_HPP_INCLUDED

#include <fcppt/metal/set/make.hpp>
#include <fcppt/metal/set/to_list.hpp>
#include <fcppt/metal/set/union.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace record
{
/**
\brief Tests if multiple records have disjoint label sets

\ingroup fcpptrecord

\tparam Records A metal list.
*/
template <typename Records>
using all_disjoint = std::is_same<
    ::metal::size<::metal::accumulate<
        ::metal::bind<
            ::metal::lambda<fcppt::metal::set::union_>,
            ::metal::bind<::metal::lambda<fcppt::record::label_set>, ::metal::_2>,
            ::metal::_1>,
        ::fcppt::metal::set::make<>,
        Records>>,
    ::metal::size<::metal::flatten<::metal::transform<
        ::metal::bind<
            ::metal::lambda<fcppt::metal::set::to_list>,
            ::metal::bind<::metal::lambda<fcppt::record::label_set>, ::metal::_1>>,
        Records>>>>;

}
}

#endif
