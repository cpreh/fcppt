//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_IS_TAG_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_IS_TAG_HPP_INCLUDED

#include <fcppt/record/detail/tag_base.hpp>
#include <fcppt/type_traits/is_base_of.hpp>

namespace fcppt::record::detail
{
template <typename Type>
using is_tag = fcppt::type_traits::is_base_of<fcppt::record::detail::tag_base, Type>;

}

#endif
