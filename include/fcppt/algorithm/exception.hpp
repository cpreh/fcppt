//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_EXCEPTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace algorithm
{

/**
 * \brief The exception thrown by some algorithm operations
 * \ingroup fcpptalgorithm
 */
class exception
:
	public fcppt::exception
{
public:
	explicit exception(
		fcppt::string const &
	);
};

}
}

#include <fcppt/algorithm/impl/exception.hpp>

#endif
