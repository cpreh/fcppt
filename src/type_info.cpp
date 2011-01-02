//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_info.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/assert.hpp>
#include <fcppt/workarounds.hpp>

fcppt::type_info::type_info(
	std::type_info const &ti
)
:
	info_(&ti)
{
	FCPPT_ASSERT(info_);
}

bool
fcppt::type_info::before(
	type_info const &rhs
) const
{
	FCPPT_ASSERT(info_);

	return
		info_->before(
			*rhs.info_
		)
#ifdef FCPPT_MSVC_WRONG_TYPE_INFO_BEFORE_BUG
		!= 0
#endif
		;
}

std::type_info const &
fcppt::type_info::get() const
{
	FCPPT_ASSERT(info_);

	return *info_;
}

fcppt::string const
fcppt::type_info::name() const
{
	FCPPT_ASSERT(info_);

	return type_name(*this);
}

bool
fcppt::operator==(
	type_info const &lhs,
	type_info const &rhs
)
{
	return lhs.get() == rhs.get();
}

bool
fcppt::operator<(
	type_info const &lhs,
	type_info const &rhs
)
{
	return lhs.before(rhs);
}

bool
fcppt::operator!=(
	type_info const &lhs,
	type_info const &rhs
)
{
	return !(lhs == rhs);
}

bool
fcppt::operator>(
	type_info const &lhs,
	type_info const &rhs
)
{
	return rhs < lhs;
}

bool
fcppt::operator<=(
	type_info const &lhs,
	type_info const &rhs
)
{
	return !(lhs > rhs);
}

bool
fcppt::operator>=(
	type_info const &lhs,
	type_info const &rhs
)
{
	return !(lhs < rhs);
}
