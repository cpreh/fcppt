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
	typedef
	Enum
	enum_type;

	typedef
	fcppt::enum_::size<
		Enum
	>
	static_size;

	typedef
	std::array<
		Value,
		static_size::value
	>
	internal;

	typedef
	typename
	internal::value_type
	value_type;

	typedef
	typename
	internal::difference_type
	difference_type;

	typedef
	typename
	internal::size_type
	size_type;

	typedef
	typename
	internal::reference
	reference;

	typedef
	typename
	internal::const_reference
	const_reference;

	typedef
	typename
	internal::pointer
	pointer;

	typedef
	typename
	internal::const_pointer
	const_pointer;

	typedef
	typename
	internal::iterator
	iterator;

	typedef
	typename
	internal::const_iterator
	const_iterator;

	typedef
	typename
	internal::reverse_iterator
	reverse_iterator;

	typedef
	typename
	internal::const_reverse_iterator
	const_reverse_iterator;

	reference
	operator[](
		Enum
	);

	const_reference
	operator[](
		Enum
	) const;

	reference
	front();

	const_reference
	front() const;

	reference
	back();

	const_reference
	back() const;

	pointer
	data();

	const_pointer
	data() const;

	iterator
	begin();

	iterator
	end();

	const_iterator
	cbegin() const;

	const_iterator
	cend() const;

	const_iterator
	begin() const;

	const_iterator
	end() const;

	reverse_iterator
	rbegin();

	reverse_iterator
	rend();

	const_reverse_iterator
	crbegin() const;

	const_reverse_iterator
	crend() const;

	const_reverse_iterator
	rbegin() const;

	const_reverse_iterator
	rend() const;

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

	internal const &
	impl() const;

// Not private so array is still a POD
	static
	typename
	internal::size_type
	to_index(
		Enum
	);

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
