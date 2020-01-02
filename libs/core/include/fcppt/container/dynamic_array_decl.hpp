//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DYNAMIC_ARRAY_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_DYNAMIC_ARRAY_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/container/dynamic_array_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief An array of dynamic size that does not initialize.

\ingroup fcpptcontainer

\tparam T Must be a POD type.

\tparam A The allocator type.
*/
template<
	typename T,
	typename A
>
class dynamic_array
{
	static_assert(
		std::is_pod<
			T
		>::value,
		"T must be a POD"
	);

	FCPPT_NONCOPYABLE(
		dynamic_array
	);
public:
	typedef
	typename
	A::pointer
	pointer;

	typedef
	typename
	A::const_pointer
	const_pointer;

	typedef
	typename
	A::size_type
	size_type;

	explicit
	dynamic_array(
		size_type,
		A a = A()
	);

	~dynamic_array()
	noexcept;

	pointer
	data()
	noexcept;

	const_pointer
	data() const
	noexcept;

	pointer
	data_end()
	noexcept;

	const_pointer
	data_end() const
	noexcept;

	size_type
	size() const
	noexcept;
private:
	A alloc_;

	pointer data_;

	size_type size_;
};

}
}

#endif
