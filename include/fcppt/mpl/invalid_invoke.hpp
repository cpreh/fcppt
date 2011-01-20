//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INVALID_INVOKE_HPP_INCLUDED
#define FCPPT_MPL_INVALID_INVOKE_HPP_INCLUDED

#include <fcppt/mpl/exception.hpp>

namespace fcppt
{
namespace mpl
{

/// Thrown by an invalid invoke
class invalid_invoke
:
	public mpl::exception
{
public:
	explicit invalid_invoke();
};

}
}

#include <fcppt/mpl/impl/invalid_invoke.hpp>

#endif
