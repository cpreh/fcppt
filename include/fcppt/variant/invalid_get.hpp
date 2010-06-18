//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_INVALID_GET_HPP_INCLUDED
#define FCPPT_VARIANT_INVALID_GET_HPP_INCLUDED

#include <fcppt/variant/exception.hpp>

namespace fcppt
{
namespace variant
{

/// Thrown if an invalid get<T> is called
class invalid_get
:
	public variant::exception
{
public:
	invalid_get();
};

}
}

#include <fcppt/variant/impl/invalid_get.hpp>

#endif
