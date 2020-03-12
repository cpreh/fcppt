//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_SIZE_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_SIZE_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief An integer type used to describe a type index

\ingroup fcpptvariant

\see fcppt::variant::object::type_index
*/
using
size_type
=
std::size_t;

}
}

#endif
