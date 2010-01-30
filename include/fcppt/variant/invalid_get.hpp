//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_INVALID_GET_HPP_INCLUDED
#define FCPPT_VARIANT_INVALID_GET_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace variant
{

class invalid_get : public exception {
public:
	FCPPT_SYMBOL invalid_get();
};

}
}

#endif
