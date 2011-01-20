//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BAD_LEXICAL_CAST_HPP_INCLUDED
#define FCPPT_BAD_LEXICAL_CAST_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/type_info.hpp>

namespace fcppt
{

/// May be thrown by lexical_cast if the cast fails
class bad_lexical_cast
:
	public exception
{
public:
	explicit bad_lexical_cast(
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

#include <fcppt/impl/bad_lexical_cast.hpp>

#endif
