//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BAD_TRUNCATION_CHECK_CAST_HPP_INCLUDED
#define FCPPT_BAD_TRUNCATION_CHECK_CAST_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/type_info.hpp>

namespace fcppt
{

/// May be thrown by truncation_check_cast if the conversion truncates
class bad_truncation_check_cast
:
	public exception
{
public:
	explicit bad_truncation_check_cast(
		type_info const &source,
		type_info const &dest
	);

	type_info const &
	source() const;

	type_info const &
	destination() const;
private:
	type_info
		source_,
		destination_;
};

}

#include <fcppt/impl/bad_truncation_check_cast.hpp>

#endif
