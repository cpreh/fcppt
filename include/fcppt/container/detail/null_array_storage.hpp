//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_NULL_ARRAY_STORAGE_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_NULL_ARRAY_STORAGE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace detail
{

// It is important that this structure is a pod
template<
	typename T
>
struct null_array_storage
{
	T *
	get()
	{
		return nullptr;
	}

	T const *
	get() const
	{
		return nullptr;
	}

	operator T *()
	{
		return get();
	}

	operator T const *() const
	{
		return get();
	}

	T &
	operator[](
		std::size_t
	)
	{
		return *get();
	}

	T const &
	operator[](
		std::size_t
	) const
	{
		return *get();
	}
};

}
}
}

#endif
