//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_REVERSE_MEM_HPP_INCLUDED
#define FCPPT_ENDIANNESS_REVERSE_MEM_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace endianness
{

FCPPT_SYMBOL void
reverse_mem(
	unsigned char *,
	std::size_t len
);

}
}

#endif
