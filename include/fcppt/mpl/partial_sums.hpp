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


#ifndef SGE_MPL_PARTIAL_SUMS_HPP_INCLUDED
#define SGE_MPL_PARTIAL_SUMS_HPP_INCLUDED

#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/placeholders.hpp>

namespace sge
{
namespace mpl
{

template<typename Elements>
class partial_sums
:
public boost::mpl::fold<
	Elements,
	boost::mpl::vector_c<int, 0>, // mpl::plus<> converts its operands, so int is most conservative
	boost::mpl::push_back<
		boost::mpl::_1,
		boost::mpl::plus<
			boost::mpl::back<
				boost::mpl::_1
			>,
			boost::mpl::_2
		>
	>
> {};

}
}

#endif
