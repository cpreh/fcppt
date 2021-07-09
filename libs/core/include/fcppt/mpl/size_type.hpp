//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SIZE_TYPE_HPP_INCLUDED
#define FCPPT_MPL_SIZE_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{

/**
\brief The size type used by this library.
\ingroup fcpptmpl
*/
template<std::size_t I>
using size_type = std::integral_constant<std::size_t,I>;

}

#endif
