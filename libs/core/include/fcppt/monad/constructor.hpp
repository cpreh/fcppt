//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MONAD_CONSTRUCTOR_HPP_INCLUDED
#define FCPPT_MONAD_CONSTRUCTOR_HPP_INCLUDED

#include <fcppt/monad/instance_fwd.hpp>


namespace fcppt
{
namespace monad
{

template<
	typename Type,
	typename Value
>
using
constructor
=
typename
fcppt::monad::instance<
	Type
>:: template constructor<
	Value
>::type;

}
}

#endif
