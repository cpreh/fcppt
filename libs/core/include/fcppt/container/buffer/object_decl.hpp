//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BUFFER_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/container/buffer/object_fwd.hpp>
#include <fcppt/container/raw_vector/rep_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace buffer
{

/**
\brief A contiguous container for uninitialized data that contains a write and a read area.

\ingroup fcpptcontainerbuffer

\tparam T Must be a POD type.

\tparam A The allocator type.

See the \link fcpptcontainerbuffer module documentation \endlink for more information.
*/
template<
	typename T,
	typename A
>
class object
{
	static_assert(
		std::is_pod<
			T
		>::value,
		"T must be a POD"
	);

	FCPPT_NONCOPYABLE(
		object
	);
public:
	typedef
	T
	value_type;

	typedef
	A
	allocator_type;

	typedef
	typename
	A::size_type
	size_type;

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
	A::const_reference
	const_reference;

	typedef
	typename
	A::const_pointer
	const_iterator;

	/**
	\brief Constructs an uninitialized buffer.

	Constructs a buffer with a write area of size \a sz.
	*/
	explicit
	object(
		size_type write_sz,
		A a = A()
	);

	object(
		object &&
	)
	noexcept;

	object &
	operator=(
		object &&
	)
	noexcept;

	~object()
	noexcept;

	/**
	\brief The beginning of the read area.
	*/
	const_iterator
	begin() const
	noexcept;

	/**
	\brief The end of the read area.
	*/
	const_iterator
	end() const
	noexcept;

	/**
	\brief The read area at a given position.
	*/
	const_reference
	operator[](
		size_type
	) const
	noexcept;

	/**
	\brief The beginning of the read area.
	*/
	const_pointer
	read_data() const
	noexcept;

	/**
	\brief The end of the read area.
	*/
	const_pointer
	read_data_end() const
	noexcept;

	/**
	\brief The beginning of the write area.
	*/
	pointer
	write_data()
	noexcept;

	/**
	\brief The end of the write area.
	*/
	pointer
	write_data_end()
	noexcept;

	/**
	\brief The size of the read area.
	*/
	size_type
	read_size() const
	noexcept;

	/**
	\brief The size of the write area.
	*/
	size_type
	write_size() const
	noexcept;

	/**
	\brief Adds to the read area.

	Adds \a sz elements to the read area. This function should be
	called after data has been read into the write area.
	*/
	void
	written(
		size_type sz
	)
	noexcept;

	/**
	\brief Resizes the write area.

	Sets the size of the write area to \a sz.
	*/
	void
	resize_write_area(
		size_type sz
	);

	allocator_type
	get_allocator() const;

	void
	swap(
		object &
	)
	noexcept;

	/**
	\brief Releases the storage.

	\see fcppt::container::buffer::to_raw_vector
	*/
	fcppt::container::raw_vector::rep<
		A
	>
	release()
	noexcept;
private:
	void
	release_internal()
	noexcept;

/// \cond
	struct impl
	{
		FCPPT_NONCOPYABLE(
			impl
		);
	public:
		impl(
			A const &,
			pointer first,
			size_type size
		);

		impl(
			impl &&
		)
		noexcept;

		impl &
		operator=(
			impl &&
		)
		noexcept;

		~impl()
		noexcept;

		void
		deallocate()
		noexcept;

		A alloc_;

		pointer
			first_,
			read_end_,
			write_end_,
			cap_;
	};

	impl impl_;
/// \endcond
};

template<
	typename T,
	typename A
>
void
swap(
	fcppt::container::buffer::object<
		T,
		A
	> &,
	fcppt::container::buffer::object<
		T,
		A
	> &
)
noexcept;

}
}
}

#endif
