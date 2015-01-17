//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXTRACT_FROM_STRING_ERROR_HPP_INCLUDED
#define FCPPT_EXTRACT_FROM_STRING_ERROR_HPP_INCLUDED

#include <fcppt/exception.hpp>


namespace fcppt
{

/**
\brief Exception thrown by fcppt::extract_from_string_exn
\ingroup fcpptstring
*/
class extract_from_string_error
:
	public fcppt::exception
{
public:
	extract_from_string_error();
};

}

#include <fcppt/impl/extract_from_string_error.hpp>

#endif
