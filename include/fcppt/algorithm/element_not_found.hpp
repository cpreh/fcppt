//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ELEMENT_NOT_FOUND_HPP_INCLUDED
#define FCPPT_ALGORITHM_ELEMENT_NOT_FOUND_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/class_symbol.hpp>

namespace fcppt
{
namespace algorithm
{

/// May be thrown by the _exn algorithms like find_exn()
class FCPPT_CLASS_SYMBOL element_not_found
:
	public exception
{
public:
	FCPPT_SYMBOL element_not_found();
};

}
}

#endif
