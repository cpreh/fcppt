//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_FROM_LIST_FWD_HPP_INCLUDED
#define FCPPT_RECORD_FROM_LIST_FWD_HPP_INCLUDED

#include <fcppt/metal/as.hpp>
#include <fcppt/record/object_fwd.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Declares a record using a metal::list.

\ingroup fcpptrecord

\tparam List Must be a metal::list.
*/
template<
	typename List
>
using
from_list
=
fcppt::metal::as<
	fcppt::record::object,
	List
>;

}
}

#endif
