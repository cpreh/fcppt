//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/type_info.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/workarounds.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


fcppt::type_info::type_info(
	std::type_info const &_ti
)
:
	info_(&_ti)
{
}

bool
fcppt::type_info::before(
	type_info const &_rhs
) const
{
	return
		info_->before(
			*_rhs.info_
		)
#if defined(FCPPT_MSVC_WRONG_TYPE_INFO_BEFORE_BUG)
		!= 0
#endif
		;
}

std::type_info const &
fcppt::type_info::get() const
{
	return *info_;
}

fcppt::string const
fcppt::type_info::name() const
{
	return
		fcppt::type_name(
			*info_
		);
}

bool
fcppt::operator==(
	fcppt::type_info const &_lhs,
	fcppt::type_info const &_rhs
)
{
	return
		_lhs.get() == _rhs.get();
}

bool
fcppt::operator<(
	fcppt::type_info const &_lhs,
	fcppt::type_info const &_rhs
)
{
	return
		_lhs.before(
			_rhs
		);
}

bool
fcppt::operator!=(
	fcppt::type_info const &_lhs,
	fcppt::type_info const &_rhs
)
{
	return
		!(_lhs == _rhs);
}

bool
fcppt::operator>(
	fcppt::type_info const &_lhs,
	fcppt::type_info const &_rhs
)
{
	return
		_rhs < _lhs;
}

bool
fcppt::operator<=(
	fcppt::type_info const &_lhs,
	fcppt::type_info const &_rhs
)
{
	return
		!(_lhs > _rhs);
}

bool
fcppt::operator>=(
	fcppt::type_info const &_lhs,
	fcppt::type_info const &_rhs
)
{
	return
		!(_lhs < _rhs);
}
