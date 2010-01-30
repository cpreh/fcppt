//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INVALID_INVOKE_HPP_INCLUDED
#define FCPPT_MPL_INVALID_INVOKE_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace mpl
{

class FCPPT_CLASS_SYMBOL invalid_invoke
:
	public fcppt::exception
{
public:
	FCPPT_SYMBOL explicit invalid_invoke();
};

}
}

#endif
