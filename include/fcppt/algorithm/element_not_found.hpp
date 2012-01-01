//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_ELEMENT_NOT_FOUND_HPP_INCLUDED
#define FCPPT_ALGORITHM_ELEMENT_NOT_FOUND_HPP_INCLUDED

#include <fcppt/algorithm/exception.hpp>

namespace fcppt
{
namespace algorithm
{

/**
 * \brief May be thrown by the <code>_exn</code> algorithms like fcppt::algorithm::find_exn()
 * \ingroup fcpptalgorithm
*/
class element_not_found
:
	public algorithm::exception
{
public:
	element_not_found();
};

}
}

#include <fcppt/algorithm/impl/element_not_found.hpp>

#endif
