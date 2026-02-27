//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_TRAITS_SIZE_TYPE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_SIZE_TYPE_HPP_INCLUDED

namespace fcppt::type_traits
{
/**
\brief The size type of a container.

\ingroup fcppttypetraits
*/
template <typename Container>
using size_type = Container::size_type;

}

#endif
