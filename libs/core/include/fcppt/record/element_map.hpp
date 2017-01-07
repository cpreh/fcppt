//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_MAP_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_MAP_HPP_INCLUDED

#include <fcppt/record/element_map_tpl.hpp>


namespace fcppt
{
namespace record
{

/**
\brief The element map of a record

\ingroup fcpptrecord

\tparam Record Must be an \link fcppt::record::object\endlink.
*/
template<
	typename Record
>
using element_map
=
typename
fcppt::record::element_map_tpl<
	Record
>::type;

}
}

#endif
