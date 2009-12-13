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


#ifndef SGE_RANDOM_ACTOR_NORMALIZED_HPP_INCLUDED
#define SGE_RANDOM_ACTOR_NORMALIZED_HPP_INCLUDED

#include <sge/random/actor/float_type.hpp>
#include <sge/random/actor/container.hpp>
#include <sge/random/uniform.hpp>
#include <sge/export.hpp>
#include <sge/noncopyable.hpp>

namespace sge
{
namespace random
{
namespace actor
{

class normalized {
	SGE_NONCOPYABLE(normalized)
public:
	SGE_SYMBOL explicit normalized(
		container const &);

	SGE_SYMBOL ~normalized();

	SGE_SYMBOL void operator()();
private:
	typedef uniform<
		float_type
	> rng_type;

	container const elements;
	rng_type rng;
};

}
}
}

#endif
