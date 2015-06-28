//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_RANGE_DECL_HPP_INCLUDED
#define FCPPT_ENUM_RANGE_DECL_HPP_INCLUDED

#include <fcppt/enum_iterator_fwd.hpp>
#include <fcppt/enum_size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\ingroup fcpptenum
*/
template<
	typename Enum
>
class enum_range
{
public:
	typedef
	Enum
	value_type;

	typedef
	fcppt::enum_iterator<
		Enum
	>
	iterator;

	typedef
	iterator
	const_iterator;

	static_assert(
		std::is_enum<
			Enum
		>::value,
		"Enum must be an enumeration type"
	);

	typedef
	typename
	fcppt::enum_size_type<
		Enum
	>::type
	size_type;

	constexpr
	enum_range(
		size_type begin,
		size_type end
	);

	constexpr
	iterator
	begin() const;

	constexpr
	iterator
	end() const;

	constexpr
	size_type
	size() const;
private:
	size_type begin_;

	size_type end_;
};

}

#endif
