//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_VARIADIC_FWD_HPP_INCLUDED
#define FCPPT_RECORD_VARIADIC_FWD_HPP_INCLUDED

#include <fcppt/record/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Declares a record using a parameter pack.

\ingroup fcpptrecord
*/
template<
	typename... Types
>
using
variadic
=
fcppt::record::object<
	::brigand::list<
		Types...
	>
>;

}
}

#endif
