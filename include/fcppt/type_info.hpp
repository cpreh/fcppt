//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_INFO_HPP_INCLUDED
#define FCPPT_TYPE_INFO_HPP_INCLUDED

#include <fcppt/type_info_fwd.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/string.hpp>
#include <typeinfo>

//[type_info
namespace fcppt
{

class type_info
{
public:
	FCPPT_SYMBOL type_info(
		std::type_info const &
	);

	FCPPT_SYMBOL std::type_info const &
	get() const;

	FCPPT_SYMBOL bool
	before(
		type_info const &rhs
	) const;

	FCPPT_SYMBOL string const
	name() const;
//<-
private:
	std::type_info const *info_;
//->
};

FCPPT_SYMBOL bool operator==(const type_info& lhs, const type_info& rhs);

FCPPT_SYMBOL bool operator<(const type_info& lhs, const type_info& rhs);

FCPPT_SYMBOL bool operator!=(const type_info& lhs, const type_info& rhs);

FCPPT_SYMBOL bool operator>(const type_info& lhs, const type_info& rhs);

FCPPT_SYMBOL bool operator<=(const type_info& lhs, const type_info& rhs);

FCPPT_SYMBOL bool operator>=(const type_info& lhs, const type_info& rhs);

}
//]

#endif
