//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_RANGE_DECL_HPP_INCLUDED
#define FCPPT_ENUM_RANGE_DECL_HPP_INCLUDED

#include <fcppt/enum/iterator_fwd.hpp>
#include <fcppt/enum/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace enum_
{

/**
\brief A range over a contiguous enum

\ingroup fcpptenum
*/
template<
	typename Enum
>
class range
{
public:
	typedef
	Enum
	value_type;

	typedef
	fcppt::enum_::iterator<
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
	fcppt::enum_::size_type<
		Enum
	>
	size_type;

	constexpr
	range(
		size_type begin,
		size_type end
	)
	noexcept;

	constexpr
	iterator
	begin() const
	noexcept;

	constexpr
	iterator
	end() const
	noexcept;

	constexpr
	size_type
	size() const
	noexcept;
private:
	size_type begin_;

	size_type end_;
};

}
}

#endif
