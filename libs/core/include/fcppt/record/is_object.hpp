//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_IS_OBJECT_HPP_INCLUDED
#define FCPPT_RECORD_IS_OBJECT_HPP_INCLUDED

#include <fcppt/record/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Tests if a type is an #fcppt::record::object.

\ingroup fcpptrecord
*/
template<
	typename T
>
struct is_object
:
std::false_type
{
};

template<
	typename... Elements
>
struct is_object<
	fcppt::record::object<
		Elements...
	>
>
:
std::true_type
{
};

}
}

#endif
