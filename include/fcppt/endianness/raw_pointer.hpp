//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_RAW_POINTER_HPP_INCLUDED
#define FCPPT_ENDIANNESS_RAW_POINTER_HPP_INCLUDED

#include <fcppt/endianness/raw_value.hpp>


namespace fcppt
{
namespace endianness
{

/**
\brief A pointer to raw memory, used to swap bytes

\ingroup fcpptendianness
*/
typedef fcppt::endianness::raw_value *raw_pointer;

}
}

#endif
