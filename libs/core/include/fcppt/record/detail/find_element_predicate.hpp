//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_FIND_ELEMENT_PREDICATE_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_FIND_ELEMENT_PREDICATE_HPP_INCLUDED

#include <fcppt/record/element_to_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace record
{
namespace detail
{
template <typename Label>
using find_element_predicate = ::metal::bind<
    ::metal::trait<std::is_same>,
    ::metal::bind<::metal::lambda<fcppt::record::element_to_label>, ::metal::_1>,
    ::metal::always<Label>>;

}
}
}

#endif
