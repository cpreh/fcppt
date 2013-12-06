//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ENUM_ARRAY_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_ENUM_ARRAY_DECL_HPP_INCLUDED

#include <fcppt/enum_size.hpp>
#include <fcppt/container/enum_array_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

template<
	typename Enum,
	typename Value
>
class enum_array
{
public:
	typedef
	fcppt::enum_size<
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
	Enum
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
	internal::iterator
	iterator;

	typedef
	typename
	internal::const_iterator
	const_iterator;

	// TODO: Add all members of array!

	reference
	operator[](
		size_type
	);

	const_reference
	operator[](
		size_type
	) const;

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


	// Not private so enum_array is still a POD
	static
	typename
	internal::size_type
	to_index(
		size_type
	);

	internal impl_;
};

}
}

#endif
