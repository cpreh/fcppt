//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_ARRAY_DECL_HPP_INCLUDED
#define FCPPT_ENUM_ARRAY_DECL_HPP_INCLUDED

#include <fcppt/enum/array_fwd.hpp>
#include <fcppt/enum/size.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace enum_
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4623)
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief An array indexed with an enum

\ingroup fcpptenum

This class is like <code>std::array</code>, except that <code>operator[]</code>
takes a parameter of type \a Enum. This class is meant to be used with
contiguous enums.

\tparam Enum The enum type to use as an index which also determines the array's size.
*/
template<
	typename Enum,
	typename Value
>
class array
{
public:
	using
	enum_type
	=
	Enum;

	using
	static_size
	=
	fcppt::enum_::size<
		Enum
	>;

	using
	internal
	=
	std::array<
		Value,
		static_size::value
	>;

	using
	value_type
	=
	typename
	internal::value_type;

	using
	difference_type
	=
	typename
	internal::difference_type;

	using
	size_type
	=
	typename
	internal::size_type;

	using
	reference
	=
	typename
	internal::reference;

	using
	const_reference
	=
	typename
	internal::const_reference;

	using
	pointer
	=
	typename
	internal::pointer;

	using
	const_pointer
	=
	typename
	internal::const_pointer;

	using
	iterator
	=
	typename
	internal::iterator;

	using
	const_iterator
	=
	typename
	internal::const_iterator;

	using
	reverse_iterator
	=
	typename
	internal::reverse_iterator;

	using
	const_reverse_iterator
	=
	typename
	internal::const_reverse_iterator;

	[[nodiscard]]
	reference
	operator[](
		Enum
	);

	[[nodiscard]]
	const_reference
	operator[](
		Enum
	) const;

	[[nodiscard]]
	reference
	front();

	[[nodiscard]]
	const_reference
	front() const;

	[[nodiscard]]
	reference
	back();

	[[nodiscard]]
	const_reference
	back() const;

	[[nodiscard]]
	pointer
	data();

	[[nodiscard]]
	const_pointer
	data() const;

	[[nodiscard]]
	iterator
	begin();

	[[nodiscard]]
	iterator
	end();

	[[nodiscard]]
	const_iterator
	cbegin() const;

	[[nodiscard]]
	const_iterator
	cend() const;

	[[nodiscard]]
	const_iterator
	begin() const;

	[[nodiscard]]
	const_iterator
	end() const;

	[[nodiscard]]
	reverse_iterator
	rbegin();

	[[nodiscard]]
	reverse_iterator
	rend();

	[[nodiscard]]
	const_reverse_iterator
	crbegin() const;

	[[nodiscard]]
	const_reverse_iterator
	crend() const;

	[[nodiscard]]
	const_reverse_iterator
	rbegin() const;

	[[nodiscard]]
	const_reverse_iterator
	rend() const;

	[[nodiscard]]
	constexpr
	size_type
	size() const;

	void
	fill(
		Value const &
	);

	void
	swap(
		array &
	);

	[[nodiscard]]
	internal const &
	impl() const;

// Not private so array is still a POD
	[[nodiscard]]
	static
	typename
	internal::size_type
	to_index(
		Enum
	);
// NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
	internal impl_;
};

FCPPT_PP_POP_WARNING

template<
	typename Enum,
	typename Value
>
void
swap(
	fcppt::enum_::array<
		Enum,
		Value
	> &,
	fcppt::enum_::array<
		Enum,
		Value
	> &
);

}
}

#endif
