/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_ALIGNMENT_ARRAY_HPP_INCLUDED
#define SGE_ALIGNMENT_ARRAY_HPP_INCLUDED

#include <sge/alignment/size_type.hpp>
#include <sge/alignment/maximum.hpp>
#include <sge/alignment/align.hpp>
#include <tr1/array>
#include <boost/preprocessor/arithmetic/mul.hpp>
#include <boost/preprocessor/comparison/less_equal.hpp>
#include <boost/preprocessor/repetition/for.hpp>

namespace sge
{
namespace alignment
{

template<
	typename T,
	size_type Size,
	size_type Alignment
>
struct array;

#define SGE_ALIGNMENT_GENERATE_ARRAY(r, state)\
template<\
	typename T,\
	size_type Size\
>\
struct array<\
	T,\
	Size,\
	state\
> {\
	typedef SGE_ALIGNMENT_ALIGN(state) std::tr1::array<\
		T,\
		Size\
	> type;\
};

#define SGE_ALIGNMENT_GENERATE_ARRAY_END(r, state)\
	BOOST_PP_LESS_EQUAL(\
		state,\
		SGE_ALIGNMENT_MAXIMUM\
	)

#define SGE_ALIGNMENT_GENERATE_ARRAY_ADD(r, state)\
	BOOST_PP_MUL(state, 2)

BOOST_PP_FOR(
	1,
	SGE_ALIGNMENT_GENERATE_ARRAY_END,
	SGE_ALIGNMENT_GENERATE_ARRAY_ADD,
	SGE_ALIGNMENT_GENERATE_ARRAY
)

#undef SGE_ALIGNMENT_GENERATE_ARRAY_ADD
#undef SGE_ALIGNMENT_GENERATE_ARRAY_END
#undef SGE_ALIGNMENT_GENERATE_ARRAY

}
}

#endif
