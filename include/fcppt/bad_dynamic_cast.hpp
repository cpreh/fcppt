//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BAD_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_BAD_DYNAMIC_CAST_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/type_info.hpp>
#include <fcppt/class_symbol.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{

class FCPPT_CLASS_SYMBOL bad_dynamic_cast
:
	public exception
{
public:
	FCPPT_SYMBOL bad_dynamic_cast(
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

#endif
