/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2009 Thomas Heller (thom.heller@gmail.com)

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


#ifndef SGE_FUNCTION_OBJECT_FWD_HPP_INCLUDED
#define SGE_FUNCTION_OBJECT_FWD_HPP_INCLUDED

namespace sge
{

namespace function
{

/**
 * @brief a fully std tr1 compliant function object class
 *
 * This class was introduced beause the gcc implementation had problems
 * with boost::phoenix.
 * To encounter this, sge::function::object is a wrapper around std::tr1::function
 *
 */
template< typename Singature >
class object;

} // end namespace function

} // end namespace sge

#endif
