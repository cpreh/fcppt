//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_INFO_HPP_INCLUDED
#define FCPPT_TYPE_INFO_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/type_info_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

class type_info
{
public:
	FCPPT_SYMBOL
	explicit
	type_info(
		std::type_info const &
	);

	FCPPT_SYMBOL
	std::type_info const &
	get() const;

	FCPPT_SYMBOL
	bool
	before(
		fcppt::type_info const &rhs
	) const;

	FCPPT_SYMBOL
	fcppt::string const
	name() const;
private:
	std::type_info const *info_;
};

FCPPT_SYMBOL
bool
operator==(
	fcppt::type_info const &,
	fcppt::type_info const &
);

FCPPT_SYMBOL
bool
operator<(
	fcppt::type_info const &,
	fcppt::type_info const &
);

FCPPT_SYMBOL
bool
operator!=(
	fcppt::type_info const &,
	fcppt::type_info const &
);

FCPPT_SYMBOL
bool
operator>(
	fcppt::type_info const &,
	fcppt::type_info const &
);

FCPPT_SYMBOL
bool
operator<=(
	fcppt::type_info const &,
	fcppt::type_info const &
);

FCPPT_SYMBOL
bool
operator>=(
	fcppt::type_info const &,
	fcppt::type_info const &
);

}

#endif
